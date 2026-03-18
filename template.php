<?php

/**
 * Implements hook_css_alter().
 *
 * Injects computed link color CSS variables for each front-page block color
 * set. Automatically chooses between --link-color (for light backgrounds) and
 * --link-color-inverted (for dark backgrounds) based on the WCAG luminance of
 * the block's background color.
 *
 * This means site architects only need to set the block background color — the
 * link color adjusts itself.
 */
function opera_css_alter(&$css) {
  $properties = array();

  // Logo height variable — always injected so it works without Design Tokens.
  $size_map = array(
    'small'  => '48px',
    'medium' => '72px',
    'large'  => '96px',
    'xlarge' => '128px',
  );
  $logo_size   = theme_get_setting('logo_size', 'opera') ?: 'medium';
  $logo_height = isset($size_map[$logo_size]) ? $size_map[$logo_size] : '72px';
  $properties[] = '  --logo-max-height: ' . $logo_height . ';';

  // Block link colors — only when Design Tokens is active.
  if (function_exists('design_tokens_get_values')) {
    $values = design_tokens_get_values('opera');

    for ($i = 1; $i <= 9; $i++) {
      $bg_token = 'color-block-' . $i;
      if (!empty($values[$bg_token])) {
        $is_dark = _opera_color_is_dark($values[$bg_token]);

        // Compute text color: inverted (light) for dark backgrounds, default
        // (dark) for light backgrounds.
        $properties[] = '  --color-block-' . $i . '-text: var('
          . ($is_dark ? '--color-text-inverted, #ffffff' : '--color-text-default, #1a1a1a')
          . ');';

        // Compute link color using the same luminance decision.
        $properties[] = '  --color-block-' . $i . '-link: var('
          . ($is_dark ? '--link-color-inverted, #f0e6b8' : '--link-color, #6e0e0a')
          . ');';
      }
    }
  }

  $css['opera_computed_vars'] = array(
    'data'       => ":root {\n" . implode("\n", $properties) . "\n}",
    'type'       => 'inline',
    'group'      => CSS_THEME,
    'weight'     => -89,
    'every_page' => TRUE,
    'media'      => 'all',
    'preprocess' => FALSE,
    'browsers'   => array('IE' => TRUE, '!IE' => TRUE),
  );
}

/**
 * Returns TRUE if a hex color is perceptually dark.
 *
 * Uses the WCAG relative luminance formula. Colors with luminance below
 * 0.183 have sufficient contrast with white (4.5:1+), meaning they are
 * dark enough to warrant a light/inverted link color.
 *
 * @param string $hex
 *   A 6-digit hex color, with or without leading '#'.
 *
 * @return bool
 *   TRUE if the color is dark, FALSE if light.
 */
function _opera_color_is_dark($hex) {
  $hex = ltrim($hex, '#');
  if (strlen($hex) !== 6) {
    return TRUE;
  }

  $channels = array(
    hexdec(substr($hex, 0, 2)) / 255,
    hexdec(substr($hex, 2, 2)) / 255,
    hexdec(substr($hex, 4, 2)) / 255,
  );

  // Linearise each channel per the WCAG 2.1 formula.
  foreach ($channels as &$c) {
    $c = $c <= 0.03928
      ? $c / 12.92
      : pow(($c + 0.055) / 1.055, 2.4);
  }

  $luminance = 0.2126 * $channels[0]
             + 0.7152 * $channels[1]
             + 0.0722 * $channels[2];

  // Threshold: luminance below 0.183 means white has 4.5:1+ contrast.
  return $luminance < 0.183;
}

/**
 * Implements hook_preprocess_header().
 *
 * When the site architect has chosen a Phosphor icon as the logo, clears
 * $logo so the template doesn't show the image, and sets $logo_icon and
 * $logo_icon_size for the icon branch of the template.
 */
function opera_preprocess_header(&$variables) {
  $size_map = array(
    'small'  => 48,
    'medium' => 72,
    'large'  => 96,
    'xlarge' => 128,
  );
  $logo_size             = theme_get_setting('logo_size', 'opera') ?: 'medium';
  $variables['logo_icon_size'] = isset($size_map[$logo_size]) ? $size_map[$logo_size] : 72;
  $variables['logo_icon']      = '';

  $logo_type = theme_get_setting('logo_type', 'opera') ?: 'image';
  if ($logo_type !== 'icon') {
    return;
  }

  $icon_name = strtolower(trim(theme_get_setting('logo_icon_name', 'opera') ?: ''));
  if (empty($icon_name)) {
    return;
  }

  // Suppress the image logo so the template shows the icon instead.
  $variables['logo']      = '';
  $variables['logo_icon'] = $icon_name;
}

/**
 * Prepares variables for layout templates.
 *
 * @see layout.tpl.php
 */
function opera_preprocess_layout(&$variables) {
  if ($variables['is_front']) {
    // Add a special front-page class.
    $variables['classes'][] = 'layout-front';
    // Add a special front-page template suggestion.
    $original = $variables['theme_hook_original'];
    $variables['theme_hook_suggestions'][] = $original . '__front';
    $variables['theme_hook_suggestion'] = $original . '__front';

    // No sequence class needed — front.css uses explicit nth-of-type rules
    // for each block position (1–9), so no dynamic class is required.
  }
}

/**
 * Implements hook_design_tokens_info_alter().
 *
 * Hides block color groups in the Design Tokens UI that exceed the
 * declared front_page_block_count, so admins only see the slots that
 * correspond to their actual block count.
 */
function opera_design_tokens_info_alter(array &$info, $theme_name) {
  if ($theme_name !== 'opera') {
    return;
  }

  $count = (int) theme_get_setting('front_page_block_count', 'opera');
  if ($count < 1 || $count > 9) {
    $count = 3;
  }

  for ($i = $count + 1; $i <= 9; $i++) {
    $group_key = 'block_' . $i;
    unset($info['groups'][$group_key]);
    foreach ($info['tokens'] as $token_name => $token) {
      if (isset($token['group']) && $token['group'] === $group_key) {
        unset($info['tokens'][$token_name]);
      }
    }
  }
}

/**
 * Implements hook_preprocess_maintenance_page().
 */
function opera_preprocess_maintenance_page(&$variables) {
  // Google Fonts are loaded dynamically by the Design Tokens Font module based
  // on which fonts are configured. No hardcoded fonts needed here.
}

/**
 * Implements hook_preprocess_page().
 */
function opera_preprocess_page(&$variables) {
  // Google Fonts are loaded dynamically by the Design Tokens Font module based
  // on which fonts are configured. No hardcoded fonts needed here.
}

/**
 * Returns HTML for a breadcrumb trail.
 *
 * @param $variables
 *   An associative array containing:
 *   - breadcrumb: An array containing the breadcrumb links.
 */
function opera_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $output = '';
  if (!empty($breadcrumb)) {
    $output .= '<nav role="navigation" class="breadcrumb">';
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output .= '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= '<ol><li>' . implode('</li><li>', $breadcrumb) . '</li></ol>';
    $output .= '</nav>';
  }
  return $output;
}