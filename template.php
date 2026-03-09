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

    // Add the block color sequence class so front.css knows which
    // nth-of-type rules to apply.
    $sequence = (int) theme_get_setting('block_color_sequence', 'opera');
    if ($sequence < 2 || $sequence > 8) {
      $sequence = 3;
    }
    $variables['classes'][] = 'block-sequence-' . $sequence;
  }
}

/**
 * Implements hook_design_tokens_info_alter().
 *
 * Hides block color groups in the Design Tokens UI that exceed the
 * current block_color_sequence setting, so admins only see the slots
 * that are actually in use.
 */
function opera_design_tokens_info_alter(array &$info, $theme_name) {
  if ($theme_name !== 'opera') {
    return;
  }

  $sequence = (int) theme_get_setting('block_color_sequence', 'opera');
  if ($sequence < 2 || $sequence > 8) {
    $sequence = 3;
  }

  for ($i = $sequence + 1; $i <= 8; $i++) {
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