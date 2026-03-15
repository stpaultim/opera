<?php
/**
 * @file
 * Theme settings file for Opera.
 */

/**
 * Implements hook_form_system_theme_settings_alter().
 */
/**
 * Implements hook_form_system_theme_settings_alter().
 */
function opera_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL) {

  $design_tokens_active = module_exists('design_tokens');

  if ($design_tokens_active) {
    $form['colors'] = array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('Configure colors and fonts for this theme on the <a href="!url">Design Tokens</a> page.', array('!url' => url('admin/appearance/tokens/opera'))) . '</p>',
    );
  }
  else {
    // @todo Once Design Tokens is published on BackdropCMS.org, replace the
    // plain "Design Tokens" text in the message below with a link to its
    // project page (e.g. https://backdropcms.org/project/design_tokens).
    // In the meantime it links to the Opera theme page so the placeholder is
    // obvious and easy to find when the module is live.
    $design_tokens_url = 'https://backdropcms.org/project/opera';
    $form['design_tokens_notice'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="messages info"><p>' . t('Opera works great out of the box with its built-in color scheme and typography. To unlock full control — custom colors, fonts, and preset schemes — install the <a href="!url" target="_blank" rel="noopener"><strong>Design Tokens</strong></a> module. It replaces Opera\'s default styles with many configurable options (color, font, and others).', array('!url' => $design_tokens_url)) . '</p></div>',
    );
  }

  $front_page_description = $design_tokens_active
    ? t('The first and last blocks are always white. Middle blocks cycle through the color sequence defined in <a href="!url">Design Tokens</a>.', array('!url' => url('admin/appearance/tokens/opera')))
    : t('The first and last blocks are always white. Middle blocks cycle through the numbered color sets. Install the Design Tokens module to customize these colors.');

  $form['header'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Header'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#weight'      => 5,
  );
  $form['header']['logo_type'] = array(
    '#type'          => 'radios',
    '#title'         => t('Logo type'),
    '#options'       => array(
      'image' => t('Image — upload via Administration > Configuration > System > Site information'),
      'icon'  => t('Phosphor icon'),
    ),
    '#default_value' => theme_get_setting('logo_type', 'opera') ?: 'image',
  );
  if (module_exists('icon_browser')) {
    $icon_browse_link = t('<a href="@url" target="_blank">Browse all available icons</a>.', array(
      '@url' => url('admin/config/media/icons/browse'),
    ));
  }
  else {
    $icon_browse_link = t('Install the <a href="@url" target="_blank">Icon Browser</a> module to visually browse all available icons.', array(
      '@url' => 'https://backdropcms.org/project/icon_browser',
    ));
  }

  $form['header']['logo_icon_name'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Icon name'),
    '#default_value' => theme_get_setting('logo_icon_name', 'opera') ?: '',
    '#description'   => t('Enter a Phosphor icon name such as %house, %star, or %buildings. !browse', array(
      '%house'     => 'house',
      '%star'      => 'star',
      '%buildings' => 'buildings',
      '!browse'    => $icon_browse_link,
    )),
    '#attributes'    => array('class' => array('opera-logo-icon-field')),
    '#states'        => array(
      'visible' => array(
        ':input[name="logo_type"]' => array('value' => 'icon'),
      ),
    ),
  );

  $icon_name    = strtolower(trim(theme_get_setting('logo_icon_name', 'opera') ?: ''));
  $preview_html = $icon_name ? icon($icon_name, array('attributes' => array('width' => 48, 'height' => 48))) : '';
  $form['header']['icon_preview'] = array(
    '#type'       => 'container',
    '#attributes' => array('id' => 'opera-icon-preview-wrapper'),
    '#states'     => array(
      'visible' => array(
        ':input[name="logo_type"]' => array('value' => 'icon'),
      ),
    ),
    'icon'        => array(
      '#markup' => $preview_html ?: '<em>' . t('Enter a valid icon name to see a preview.') . '</em>',
    ),
    '#attached'   => array(
      'js' => array(
        backdrop_get_path('theme', 'opera') . '/js/admin-header.js',
      ),
    ),
  );
  $form['header']['logo_size'] = array(
    '#type'          => 'select',
    '#title'         => t('Logo size'),
    '#options'       => array(
      'small'  => t('Small (48px)'),
      'medium' => t('Medium (72px)'),
      'large'  => t('Large (96px)'),
      'xlarge' => t('X-Large (128px)'),
    ),
    '#default_value' => theme_get_setting('logo_size', 'opera') ?: 'medium',
    '#description'   => t('Maximum height of the logo image in the header bar. Choose a larger size for logos with fine detail or complex wordmarks, smaller for simple icon-style marks.'),
  );

  $form['front_page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Front Page Block Colors'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => $front_page_description,
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

  if ($design_tokens_active) {
    $form['fonts'] = array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('Fonts are managed through <a href="!url">Design Tokens</a>. Google Fonts are loaded automatically based on your selections.', array('!url' => url('admin/appearance/tokens/opera'))) . '</p>',
    );
  }

  // Recommended modules section.
  // Detect whether the Project Browser is available. If so, we link
  // uninstalled modules to the installer rather than the external project page.
  // @todo Verify the query parameter name for the Project Browser modal once
  //   the Project Browser module version is known. 'filter' is a common pattern
  //   but may need to be adjusted to match the actual implementation.
  $has_project_browser = backdrop_valid_path('admin/modules/install');

  $modules = array(
    array(
      'name'        => 'Configurable Block Styles',
      'machine'     => 'configurable_block_style',
      'project_url' => 'https://backdropcms.org/project/configurable_block_style',
      'description' => t('Apply predefined CSS style presets to individual blocks from the layout editor. Works well with Opera\'s color system to assign specific color sets to blocks without editing CSS.'),
    ),
    array(
      'name'        => 'Nice Messages',
      'machine'     => 'nicemessages',
      'project_url' => 'https://backdropcms.org/project/nicemessages',
      'description' => t('Improves the appearance of status, warning, and error messages with cleaner styling and icons. Makes system feedback feel like part of your design rather than an afterthought.'),
    ),
    array(
      'name'        => 'Tab Icons',
      'machine'     => 'tab_icons',
      'project_url' => 'https://backdropcms.org/project/tab_icons',
      'description' => t('Adds icons to local task tabs such as View, Edit, and Delete. Makes the admin interface more visually intuitive, especially for people new to Backdrop.'),
    ),
    array(
      'name'        => 'Custom Breadcrumbs',
      'machine'     => 'custom_breadcrumbs',
      'project_url' => 'https://backdropcms.org/project/custom_breadcrumbs',
      'description' => t('Take full control of the breadcrumb trail on any page. Define custom paths and labels to help visitors understand where they are on your site.'),
    ),
  );

  $cards = '';
  foreach ($modules as $module) {
    $installed = module_exists($module['machine']);
    $card_class = 'opera-module-card' . ($installed ? ' opera-module-card--installed' : '');

    // Status badge.
    if ($installed) {
      $status = '<span class="opera-module-status opera-module-status--installed">' . t('Installed') . '</span>';
    }
    else {
      $status = '<span class="opera-module-status opera-module-status--available">' . t('Not installed') . '</span>';
    }

    // Module name always links to the project page for reference.
    $name_link = l(
      check_plain($module['name']),
      $module['project_url'],
      array('attributes' => array('target' => '_blank', 'rel' => 'noopener'))
    );

    // Install link: use the best available mechanism.
    // Getting Started module provides a route that pre-populates the Project
    // Browser search field via a session variable — use it when available.
    // Otherwise link directly to the install page, or fall back to the
    // project page if the Project Browser is not installed at all.
    $install_link = '';
    if (!$installed) {
      if (module_exists('getting_started') && $has_project_browser) {
        $installer_url = url('admin/getting-started/browse/modules/' . $module['name']);
        $install_link = '<a href="' . $installer_url . '" class="opera-module-install-link">' . t('Install') . '</a>';
      }
      elseif ($has_project_browser) {
        $installer_url = url('admin/modules/install');
        $install_link = '<a href="' . $installer_url . '" class="opera-module-install-link">' . t('Install') . '</a>';
      }
      else {
        $install_link = '<a href="' . check_url($module['project_url']) . '" class="opera-module-install-link" target="_blank" rel="noopener">' . t('Download') . '</a>';
      }
    }

    $cards .= '<div class="' . $card_class . '">'
      . '<div class="opera-module-card-header">'
      . '<h4 class="opera-module-name">' . $name_link . '</h4>'
      . $status
      . '</div>'
      . '<p class="opera-module-description">' . $module['description'] . '</p>'
      . (!empty($install_link) ? '<div class="opera-module-actions">' . $install_link . '</div>' : '')
      . '</div>';
  }

  // Recommended recipes section.
  $recipes = array(
    array(
      'name'         => 'FAQ Recipe',
      'content_type' => 'faq',
      'project_url'  => 'https://backdropcms.org/project/faq_recipe',
      'description'  => t('Adds a Frequently Asked Questions content type with a view for displaying Q&A pairs. Great for support pages, help sections, and product documentation.'),
    ),
    array(
      'name'         => 'Services Recipe',
      'content_type' => 'service',
      'project_url'  => 'https://backdropcms.org/project/services_recipe',
      'description'  => t('Creates a Services content type and a front-page block to showcase what your organization offers. Opera provides grid styling for this recipe out of the box.'),
    ),
    array(
      'name'         => 'Portfolio Projects Recipe',
      'content_type' => 'portfolio_project',
      'project_url'  => 'https://backdropcms.org/project/portfolio_projects_recipe',
      'description'  => t('Adds a Portfolio Project content type with image and description fields, plus a front-page block and full listing page. Opera themes both the grid block and the projects page.'),
    ),
    array(
      'name'         => 'Testimonial Recipe',
      'content_type' => 'testimonial',
      'project_url'  => 'https://backdropcms.org/project/testimonial_recipe',
      'description'  => t('Creates a Testimonials content type and a front-page block showing customer or client quotes with portrait photos. Opera styles these as a 3-column card grid with circular avatars.'),
    ),
    array(
      'name'         => 'Slideshow Recipe',
      'content_type' => 'slide',
      'project_url'  => 'https://backdropcms.org/project/slide_show_recipe',
      'description'  => t('Adds a Slide content type and a full-width slideshow block for the front page. Ideal for hero-area promotions and featured content.'),
    ),
    array(
      'name'         => 'Gallery Recipe',
      'content_type' => 'gallery',
      'project_url'  => 'https://backdropcms.org/project/gallery_recipe',
      'description'  => t('Creates a Gallery content type with image fields and a browseable gallery view. Perfect for portfolios, event photos, and visual showcases.'),
    ),
  );

  $recipe_cards = '';
  foreach ($recipes as $recipe) {
    $node_types = node_type_get_types();
    $installed = isset($node_types[$recipe['content_type']]);
    $card_class = 'opera-module-card' . ($installed ? ' opera-module-card--installed' : '');

    if ($installed) {
      $status = '<span class="opera-module-status opera-module-status--installed">' . t('Installed') . '</span>';
    }
    else {
      $status = '<span class="opera-module-status opera-module-status--available">' . t('Not installed') . '</span>';
    }

    $name_link = l(
      check_plain($recipe['name']),
      $recipe['project_url'],
      array('attributes' => array('target' => '_blank', 'rel' => 'noopener'))
    );

    $install_link = '';
    if (!$installed) {
      if ($has_project_browser) {
        $install_link = '<a href="' . url('admin/modules/install') . '" class="opera-module-install-link">' . t('Install') . '</a>';
      }
      else {
        $install_link = '<a href="' . check_url($recipe['project_url']) . '" class="opera-module-install-link" target="_blank" rel="noopener">' . t('Download') . '</a>';
      }
    }

    $recipe_cards .= '<div class="' . $card_class . '">'
      . '<div class="opera-module-card-header">'
      . '<h4 class="opera-module-name">' . $name_link . '</h4>'
      . $status
      . '</div>'
      . '<p class="opera-module-description">' . $recipe['description'] . '</p>'
      . (!empty($install_link) ? '<div class="opera-module-actions">' . $install_link . '</div>' : '')
      . '</div>';
  }

  $form['recommended_recipes'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Recommended Recipes'),
    '#description' => t('These recipes are supported by Opera with built-in CSS styling. Click a recipe name to visit its project page.'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
    '#weight'      => 51,
  );
  $form['recommended_recipes']['list'] = array(
    '#markup' => '<div class="opera-module-grid">' . $recipe_cards . '</div>',
    '#attached' => array(
      'css' => array(
        backdrop_get_path('theme', 'opera') . '/css/admin/recommended-modules.css',
      ),
    ),
  );

  $form['recommended_modules'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Recommended Modules'),
    '#description' => t('These modules pair well with Opera. Click a module name to visit its project page, or use the Install / Download link to get it.'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
    '#weight'      => 50,
  );
  $form['recommended_modules']['list'] = array(
    '#markup' => '<div class="opera-module-grid">' . $cards . '</div>',
    '#attached' => array(
      'css' => array(
        backdrop_get_path('theme', 'opera') . '/css/admin/recommended-modules.css',
      ),
    ),
  );
}
