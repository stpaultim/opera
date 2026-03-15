/**
 * @file
 * Admin JS for Opera theme header settings — provides live icon preview.
 */
(function ($) {

  /**
   * Keeps the core "Logo image" toggle in sync with Opera's logo type setting.
   *
   * When icon mode is selected, the toggle is checked automatically so the
   * logo variable is available in the header template. On page load, corrects
   * the state if it was left out of sync.
   */
  Backdrop.behaviors.operaLogoTypeSync = {
    attach: function (context, settings) {
      var $inputs = $('input[name="logo_type"]', context).once('opera-logo-type-sync');
      if (!$inputs.length) {
        return;
      }

      function syncToggle() {
        if ($('input[name="logo_type"]:checked').val() === 'icon') {
          $('input[name="toggle_logo"]').prop('checked', true);
        }
      }

      $inputs.on('change', syncToggle);
      syncToggle();
    }
  };

  Backdrop.behaviors.operaLogoIconPreview = {
    attach: function (context, settings) {
      var $input = $('.opera-logo-icon-field', context).once('opera-logo-icon-preview');
      if (!$input.length) {
        return;
      }

      var $preview = $('#opera-icon-preview-wrapper');
      var basePath = settings.basePath || '/';
      var debounceTimer;

      /**
       * Fetches the SVG from core/misc/icons and injects it into the preview.
       */
      function updatePreview(iconName) {
        iconName = $.trim(iconName).toLowerCase();
        if (!iconName) {
          $preview.html('<em>' + Backdrop.t('Enter an icon name to see a preview.') + '</em>');
          return;
        }
        $.ajax({
          url: basePath + 'core/misc/icons/' + iconName + '.svg',
          dataType: 'text',
          success: function (svgText) {
            svgText = svgText.replace('<svg ', '<svg width="48" height="48" aria-hidden="true" ');
            $preview.html(svgText);
          },
          error: function () {
            $preview.html('<em>' + Backdrop.t('"@name" not found — check the icon name.', {'@name': iconName}) + '</em>');
          }
        });
      }

      // Debounced update while typing.
      $input.on('keyup', function () {
        clearTimeout(debounceTimer);
        var val = $(this).val();
        debounceTimer = setTimeout(function () {
          updatePreview(val);
        }, 400);
      });

      // Immediate update on autocomplete select or when focus leaves the field.
      $input.on('change blur', function () {
        clearTimeout(debounceTimer);
        updatePreview($(this).val());
      });
    }
  };

})(jQuery);
