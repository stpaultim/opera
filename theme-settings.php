<?php
/**
 * @file
 * Theme settings file for Opera.
 */

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function opera_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL) {

  $form['colors'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('Configure colors for this theme on the <a href="!url">Theme Tokens</a> page.', array('!url' => url('admin/appearance/tokens/opera'))) . '</p>',
  );

  $form['front_page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Front Page Block Colors'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('The first and last blocks are always white. Middle blocks cycle through the color sequence defined in <a href="!url">Theme Tokens</a>.', array('!url' => url('admin/appearance/tokens/opera'))),
  );
  $form['front_page']['block_color_sequence'] = array(
    '#type' => 'select',
    '#title' => t('Color sequence length'),
    '#options' => array(
      '2' => t('2'),
      '3' => t('3'),
      '4' => t('4'),
      '5' => t('5'),
      '6' => t('6'),
      '7' => t('7'),
      '8' => t('8'),
    ),
    '#default_value' => (string) (theme_get_setting('block_color_sequence', 'opera') ?: 3),
    '#description' => t('Number of distinct block colors before the sequence repeats.'),
  );

  $form['fonts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Font Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fonts']['use_google_fonts'] = array(
    '#type' => 'checkbox',
    '#title' => t('Load Google Fonts (Lato & Merriweather)'),
    '#description' => t('Disable to prevent requests to Google servers, e.g. for GDPR compliance.'),
    '#default_value' => theme_get_setting('use_google_fonts', 'opera') !== 0,
  );
}
