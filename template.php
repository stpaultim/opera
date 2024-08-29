<?php

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
  } else {
    $variables['classes'][] = 'not-front';
  }
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

/**
 * Implements hook_css_alter().
 */
function opera_css_alter(&$css) {
  $theme_path = backdrop_get_path('theme', 'opera');

  if ($opera_cdn = theme_get_setting('opera_cdn')) {
    $use_bootstrap = theme_get_setting('use_bootstrap');
    if ($use_bootstrap == 1) {
      $cdn = 'https://cdn.jsdelivr.net/npm/bootstrap@' . $opera_cdn  . '/dist/css/bootstrap.min.css';
      $css[$cdn] = array(
        'data' => $cdn,
        'type' => 'external',
        'every_page' => TRUE,
        'every_page_weight' => -1,
        'media' => 'all',
        'preprocess' => FALSE,
        'group' => CSS_THEME,
        'browsers' => array('IE' => TRUE, '!IE' => TRUE),
        'weight' => -2,
        'attributes' => array(),
      );
    }
  }
}

function opera_preprocess_block(&$variables) {
  $uuid = $variables['block']->uuid;
  $variables['region'] = $variables['layout']->getBlockPosition($uuid);
  // backdrop_set_message($variables['region']);
}

/**
 * Prepares variables for header templates.
 *
 * @see header.tpl.php
 */
function opera_preprocess_header(&$variables) {
  $logo = $variables['logo'];
  $logo_attributes = $variables['logo_attributes'];

  // Add classes and height/width to logo.
  if ($logo) {
    $logo_wrapper_classes = array();
    $logo_wrapper_classes[] = 'header-logo-wrapper';
    if ($logo_attributes['width'] <= $logo_attributes['height']) {
      $logo_wrapper_classes[] = 'header-logo-tall';
    }

    $variables['logo_wrapper_classes'] = $logo_wrapper_classes;
  }
}

/**
 * Implements hook_preprocess_page().
 */
function opera_preprocess_page(&$variables) {
  $no_old_ie_compatibility_modes = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'X-UA-Compatible',
      'content' => 'IE=edge',
    ),
  );

  // Add the Lato and Merriweather font to the header.
  backdrop_add_html_head_link(array(
    'rel' => 'preconnect',
    // Force the URL to be absolute, for consistency with other <link> tags
    // output by Backdrop.
    'href' => 'https://fonts.googleapis.com',
  ));

  backdrop_add_html_head_link(array(
    'rel' => 'preconnect',
    // Force the URL to be absolute, for consistency with other <link> tags
    // output by Backdrop.
    'href' => 'https://fonts.gstatic.com',
  ));

  backdrop_add_html_head_link(array(
    'rel' => 'stylesheet',
    // Force the URL to be absolute, for consistency with other <link> tags
    // output by Backdrop.
    'href' => 'https://fonts.googleapis.com/css2?family=Lato:wght@100;300;400;700;900&family=Merriweather:wght@300;400;700;900&display=swap',
  ));
}
