/**
 * @file
 * Opera-specific Design Tokens admin preview support.
 *
 * Opera computes --color-block-N-text and --color-block-N-link at PHP render
 * time based on each block's background luminance. This file mirrors that
 * logic in JavaScript so the live preview iframe stays accurate when colors
 * are changed in the admin form — including when a preset scheme is applied.
 *
 * Loaded automatically by design_tokens.admin.inc when this file is present.
 */
(function ($) {

  'use strict';

  /**
   * Computes the WCAG relative luminance of a hex color.
   *
   * Mirrors _opera_color_is_dark() in template.php — must use the same
   * threshold (0.183) and the same linearisation formula.
   *
   * @param {string} hex  A 6-digit hex color, with or without '#'.
   * @return {number}     Luminance in the range [0, 1].
   */
  function hexLuminance(hex) {
    hex = hex.replace('#', '');
    if (hex.length !== 6) {
      return 0.5;
    }
    var r = parseInt(hex.substr(0, 2), 16) / 255;
    var g = parseInt(hex.substr(2, 2), 16) / 255;
    var b = parseInt(hex.substr(4, 2), 16) / 255;

    function lin(c) {
      return c <= 0.03928 ? c / 12.92 : Math.pow((c + 0.055) / 1.055, 2.4);
    }

    return 0.2126 * lin(r) + 0.7152 * lin(g) + 0.0722 * lin(b);
  }

  /**
   * Returns TRUE if the color is dark enough to require light text/links.
   */
  function isDark(hex) {
    return hexLuminance(hex) < 0.183;
  }

  /**
   * Reads the current value of a token field, falling back to a default.
   *
   * @param {string} tokenName  The data-token-name attribute value.
   * @param {string} fallback   Value to return if field is absent or invalid.
   * @return {string}
   */
  function getTokenFieldVal(tokenName, fallback) {
    var $field = $('[data-token-name="' + tokenName + '"]');
    if (!$field.length) {
      return fallback;
    }
    var val = $field.val().toLowerCase();
    return /^#[0-9a-f]{6}$/.test(val) ? val : fallback;
  }

  /**
   * Sends computed --color-block-N-text and --color-block-N-link to the
   * preview iframe for a single block number.
   *
   * Reads the current values of the global text/link tokens from the form
   * fields so the preview reflects any in-progress changes to those too.
   *
   * @param {number} n       Block number (1–8).
   * @param {string} bgHex   The block's background color in #rrggbb format.
   */
  function updateBlockComputedColors(n, bgHex) {
    if (!/^#[0-9a-f]{6}$/.test(bgHex)) {
      return;
    }

    var dark = isDark(bgHex);

    var textColor = dark
      ? getTokenFieldVal('color-text-inverted', '#ffffff')
      : getTokenFieldVal('color-text-default',  '#1a1a1a');

    var linkColor = dark
      ? getTokenFieldVal('link-color-inverted', '#f0e6b8')
      : getTokenFieldVal('link-color',          '#6e0e0a');

    Backdrop.designTokens.updatePreview('color-block-' + n + '-text', textColor);
    Backdrop.designTokens.updatePreview('color-block-' + n + '-link', linkColor);
  }

  /**
   * Sends computed colors for all 9 block color slots.
   *
   * Called on iframe load and when any global text/link token changes.
   */
  function updateAllBlockComputedColors() {
    for (var i = 1; i <= 9; i++) {
      var bg = getTokenFieldVal('color-block-' + i, '');
      if (bg) {
        updateBlockComputedColors(i, bg);
      }
    }
  }

  Backdrop.behaviors.operaDesignTokensPreview = {
    attach: function (context, settings) {

      // When a block background color field changes, update that block's
      // computed text and link colors in the preview.
      $('[data-token-name]', context).once('opera-computed-colors').each(function () {
        var $field = $(this);
        var tokenName = $field.data('token-name');

        // color-block-N → update computed colors for that specific block.
        var blockMatch = String(tokenName).match(/^color-block-(\d+)$/);
        if (blockMatch) {
          $field.on('input change', function () {
            var val = $field.val().toLowerCase();
            updateBlockComputedColors(parseInt(blockMatch[1], 10), val);
          });
          return;
        }

        // Global text/link token change → recompute all blocks, since the
        // computed value depends on these tokens as well.
        var globalTriggers = [
          'color-text-inverted',
          'color-text-default',
          'link-color-inverted',
          'link-color'
        ];
        if (globalTriggers.indexOf(String(tokenName)) !== -1) {
          $field.on('input change', function () {
            updateAllBlockComputedColors();
          });
        }
      });

      // When the preview iframe (re)loads, send the computed colors for all
      // blocks. The parent initPreview() already replays the direct token
      // values; this adds the derived ones.
      $('#design-tokens-preview-iframe', context)
        .once('opera-preview-computed-init')
        .on('load', function () {
          updateAllBlockComputedColors();
        });
    }
  };

}(jQuery));
