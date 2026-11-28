<?php
/**
 * @file
 * Theme Tokens declaration for Opera.
 *
 * Defines the tokens available for Opera, their labels, groupings and preset
 * color schemes. Default values come from css/opera-variables.css.
 */

$info = array(

  // CSS file containing default :root {} variable values. Theme Tokens removes
  // this file from the page when active, since it injects the values itself.
  'variables_file' => 'css/opera-variables.css',

  // Sections group related token groups under a labeled divider on the admin page.
  'sections' => array(
    array(
      'label'  => 'Site Colors',
      'groups' => array('header', 'header_bar', 'secondary', 'buttons', 'links', 'cards'),
    ),
    array(
      'label'  => 'Typography',
      'groups' => array('typography'),
    ),
    array(
      'label'  => 'Front Page',
      'groups' => array('hero', 'block_1', 'block_2', 'block_3', 'block_4', 'block_5', 'block_6', 'block_7', 'block_8', 'block_9'),
    ),
  ),

  // Sub-modules that extend Design Tokens for this theme. The Design Tokens
  // admin page displays these with their enabled/disabled status.
  'submodules' => array(
    array(
      'name'        => 'Design Tokens: Color',
      'machine'     => 'design_tokens_color',
      'description' => 'Adds color pickers for all Opera color tokens and enables color scheme presets.',
    ),
    array(
      'name'        => 'Design Tokens: Fonts',
      'machine'     => 'design_tokens_font',
      'description' => 'Adds font selectors for heading and body text, including Google Fonts support.',
    ),
    array(
      'name'        => 'Design Tokens: Utility',
      'machine'     => 'design_tokens_utility',
      'description' => 'Generates CSS utility classes from token definitions, letting site architects style individual blocks by adding a class in the layout editor.',
    ),
  ),

  'groups' => array(
    'header' => array(
      'label' => t('Navigation & Footer (Primary Colors)'),
      'description' => t('The <strong>Background</strong> color here is the site\'s primary brand color. It controls the navigation bar and footer background, but also drives buttons, links, borders, blockquotes, and UI accents across the entire site. Choose it as your main brand color.'),
    ),
    'header_bar' => array(
      'label' => t('Header / Logo Bar'),
      'description' => t('Colors for the top bar containing your logo and site name. This sits above the navigation bar and is typically light or white.'),
    ),
    'secondary' => array(
      'label' => t('Secondary / Accent Color'),
      'description' => t('A complementary accent color used for interactive highlights — the active indicator bar on the navigation menu, hover accents on dropdown items, and similar decorative elements. Keeping this separate from the navigation link color means you can tune the two independently.'),
    ),
    'buttons' => array(
      'label' => t('Buttons'),
      'description' => t('Controls the appearance of primary buttons and form submit buttons across the site.'),
    ),
    'links' => array(
      'label' => t('Links & Text Colors'),
      'description' => t('Controls link colors and underline behavior for body content, plus the default and inverted text colors used automatically on colored blocks based on background brightness.'),
    ),
    'cards' => array(
      'label' => t('Cards, Tables & Panels'),
      'description' => t('Background color for content cards, post teasers, table header rows and form panels. The text color and corner radius below apply to cards and teasers only.'),
    ),
    'typography' => array(
      'label' => t('Typography'),
      'description' => t('Fonts used for headings and body text across the site.'),
    ),
    'hero' => array(
      'label' => t('Hero Blocks'),
      'description' => t('Colors for hero blocks that do not have a custom background image. These appear as a colored banner at the top of the page.'),
    ),
    'block_1' => array(
      'label' => t('Block 1'),
      'description' => t('Each front page block has its own color slot. Block 1 defaults to white. You can change how many blocks appear in the <a href="!settings_url">theme settings</a>.', array('!settings_url' => url('admin/appearance/settings/opera'))),
    ),
    'block_2' => t('Block 2'),
    'block_3' => t('Block 3'),
    'block_4' => t('Block 4'),
    'block_5' => t('Block 5'),
    'block_6' => t('Block 6'),
    'block_7' => t('Block 7'),
    'block_8' => t('Block 8'),
    'block_9' => t('Block 9'),
  ),

  'tokens' => array(

    // Typography
    'font-heading' => array(
      'label'   => t('Heading font'),
      'type'    => 'font',
      'group'   => 'typography',
      'utility' => TRUE,
    ),
    'font-body' => array(
      'label'   => t('Body font'),
      'type'    => 'font',
      'group'   => 'typography',
      'utility' => TRUE,
    ),

    // Secondary / Accent
    'color-secondary' => array(
      'label'   => t('Accent color'),
      'type'    => 'color',
      'group'   => 'secondary',
      'utility' => TRUE,
    ),

    // Buttons
    'button-bg' => array(
      'label'   => t('Button background'),
      'type'    => 'color',
      'group'   => 'buttons',
      'utility' => TRUE,
    ),
    'button-text' => array(
      'label'   => t('Button text'),
      'type'    => 'color',
      'group'   => 'buttons',
    ),
    'button-bg-hover' => array(
      'label'   => t('Button background (hover)'),
      'type'    => 'color',
      'group'   => 'buttons',
    ),
    'button-border-radius' => array(
      'label'   => t('Button corner radius'),
      'type'    => 'text',
      'description' => t('How round the corners of buttons are. Use a length such as 0 (square), 0.25rem (slightly rounded), 1rem (round) or 999px (pill-shaped).'),
      'group'   => 'buttons',
    ),
    'button-text-transform' => array(
      'label'   => t('Button text transform'),
      'type'    => 'text',
      'description' => t('How the words on buttons are capitalized.'),
      'options' => array(
        'none'       => t('None: as typed'),
        'uppercase'  => t('UPPERCASE'),
        'lowercase'  => t('lowercase'),
        'capitalize' => t('Capitalize Each Word'),
      ),
      'group'   => 'buttons',
    ),

    // Links
    'link-color' => array(
      'label'   => t('Link color'),
      'type'    => 'color',
      'group'   => 'links',
    ),
    'link-color-hover' => array(
      'label'   => t('Link color (hover)'),
      'type'    => 'color',
      'group'   => 'links',
    ),
    'link-color-visited' => array(
      'label'   => t('Link color (visited)'),
      'type'    => 'color',
      'group'   => 'links',
    ),
    'link-text-decoration' => array(
      'label'   => t('Link underline'),
      'type'    => 'text',
      'group'   => 'links',
    ),
    'link-text-decoration-hover' => array(
      'label'   => t('Link underline (hover)'),
      'type'    => 'text',
      'group'   => 'links',
    ),
    'link-color-inverted' => array(
      'label'   => t('Link color (on dark backgrounds)'),
      'type'    => 'color',
      'group'   => 'links',
    ),
    'color-text-default' => array(
      'label'   => t('Block text (on light backgrounds)'),
      'type'    => 'color',
      'group'   => 'links',
    ),
    'color-text-inverted' => array(
      'label'   => t('Block text (on dark backgrounds)'),
      'type'    => 'color',
      'group'   => 'links',
    ),

    // Header / Logo Bar
    'color-header-bg' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'group'   => 'header_bar',
    ),
    'color-header-text' => array(
      'label'   => t('Text & links'),
      'type'    => 'color',
      'group'   => 'header_bar',
      'contrast_with' => 'color-header-bg',
    ),

    // Navigation & Footer
    'color-primary' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'group'   => 'header',
      'utility' => TRUE,
    ),
    'color-primary-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'group'   => 'header',
    ),
    'color-primary-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'group'   => 'header',
    ),

    // Hero Blocks (without images)
    'color-hero' => array(
      'label'   => t('Hero background'),
      'type'    => 'color',
      'group'   => 'hero',
      'utility' => TRUE,
    ),
    'color-hero-text' => array(
      'label'   => t('Hero text'),
      'type'    => 'color',
      'group'   => 'hero',
    ),
    'color-hero-link' => array(
      'label'   => t('Hero links'),
      'type'    => 'color',
      'group'   => 'hero',
    ),

    // Cards, Tables & Panels
    // Automatic by default: calculated from the primary color in
    // opera-variables.css, until someone chooses a color.
    'color-card-bg' => array(
      'label'        => t('Card and table header background'),
      'type'         => 'color',
      'group'        => 'cards',
    ),
    // Cards keep their own text color wherever they appear, including inside
    // a colored front page block. Design Tokens checks its contrast against
    // color-card-bg.
    'color-card-text' => array(
      'label'   => t('Card text'),
      'type'    => 'color',
      'group'   => 'cards',
    ),
    'card-border-radius' => array(
      'label'   => t('Corner radius'),
      'type'    => 'text',
      'description' => t('How round the corners of cards and teasers are. Use a length such as 0 (square), 0.25rem (slightly rounded) or 1rem (round).'),
      'group'   => 'cards',
    ),

    // Block 1 — white by default, configurable.
    'color-block-1' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'group'        => 'block_1',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block 2
    'color-block-2' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'group'        => 'block_2',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block 3
    'color-block-3' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'group'        => 'block_3',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block 4
    'color-block-4' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'group'        => 'block_4',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block 5
    'color-block-5' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'group'        => 'block_5',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block 6
    'color-block-6' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'group'        => 'block_6',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block 7
    'color-block-7' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'group'        => 'block_7',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block 8
    'color-block-8' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'group'        => 'block_8',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block 9
    'color-block-9' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'group'        => 'block_9',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
  ),

  'schemes' => array(

    // Warm theatrical reds, gold, and navy — the signature Opera look.
    'default' => array(
      'title'  => t('Opera (default)'),
      // No 'tokens': this scheme uses the defaults from opera-variables.css.
    ),

    // Deep navy and teal — cool and sophisticated.
    'plume' => array(
      'title'  => t('Plume'),
      'tokens' => array(
        'color-primary'      => '#1c2541',
        'color-primary-text' => '#fef3ff',
        'color-primary-link' => '#7ec8c8',
        'color-secondary'    => '#7ec8c8',
        'color-hero'         => '#e8f4f8',
        'color-hero-text'    => '#ffffff',
        'color-hero-link'    => '#1c6ea4',
        'color-block-2'      => '#94d3c9',
        'color-block-3'      => '#0b132b',
        'color-block-4'      => '#3a506b',
      ),
    ),

    // Vivid, high-saturation — bold and energetic.
    'bright' => array(
      'title'  => t('Bright'),
      'tokens' => array(
        'color-primary'      => '#c0392b',
        'color-primary-text' => '#ffffff',
        'color-primary-link' => '#f9ca24',
        'color-secondary'    => '#f9ca24',
        'color-hero'         => '#ffeaa7',
        'color-hero-text'    => '#ffffff',
        'color-hero-link'    => '#c0392b',
        'color-block-2'      => '#f39c12',
        'color-block-3'      => '#27ae60',
        'color-block-4'      => '#2573a7',
      ),
    ),

    // Near-black backgrounds with warm muted accents — dark mode feel.
    'night' => array(
      'title'  => t('Night'),
      'tokens' => array(
        'color-primary'      => '#1a1a2e',
        'color-primary-text' => '#e0e0e0',
        'color-primary-link' => '#e94560',
        'color-secondary'    => '#e94560',
        'color-hero'         => '#16213e',
        'color-hero-text'    => '#c0c0c0',
        'color-hero-link'    => '#e94560',
        'color-block-2'      => '#0f3460',
        'color-block-3'      => '#533483',
        'color-block-4'      => '#232020',
      ),
    ),
  ),
);
