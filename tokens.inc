<?php
/**
 * @file
 * Theme Tokens declaration for Opera.
 *
 * Defines the color tokens available for Opera, their default values,
 * groupings, and preset color schemes. Requires the Theme Tokens module.
 */

$info = array(

  // CSS file containing default :root {} variable values. Theme Tokens removes
  // this file from the page when active, since it injects the values itself.
  'variables_file' => 'css/opera-variables.css',

  'groups' => array(
    'header' => array(
      'label' => t('Header & Footer (Primary Colors)'),
      'description' => t('The <strong>Background</strong> color here is the site\'s primary brand color. It controls the header and footer background, but also drives buttons, links, borders, blockquotes, and UI accents across the entire site. Choose it as your main brand color, not just a header color.'),
    ),
    'buttons' => array(
      'label' => t('Buttons'),
      'description' => t('Controls the appearance of primary buttons and form submit buttons across the site.'),
    ),
    'links' => array(
      'label' => t('Links & Text Colors'),
      'description' => t('Controls link colors and underline behavior for body content, plus the default and inverted text colors used automatically on colored blocks based on background brightness.'),
    ),
    'typography' => array(
      'label' => t('Typography'),
      'description' => t('Fonts used for headings and body text across the site.'),
    ),
    'hero' => array(
      'label' => t('Hero Blocks'),
      'description' => t('Colors for hero blocks that do not have a custom background image. These appear as a colored banner at the top of the page.'),
    ),
    'cards' => array(
      'label' => t('Cards & Teasers'),
      'description' => t('Background color and corner radius for content cards, post teasers, and similar framed content.'),
    ),
    'block_1' => array(
      'label' => t('Block Color Set 1'),
      'description' => t('On the front page, blocks in the content region cycle through these color sets. The first and last blocks are always white. Middle blocks rotate through the numbered sets (1 &rarr; 2 &rarr; 3 &rarr; 1 &rarr; 2 &rarr; 3&hellip;). You can change the number of sets being used in the <a href="!settings_url">theme settings</a>.', array('!settings_url' => url('admin/appearance/settings/opera'))),
    ),
    'block_2' => t('Block Color Set 2'),
    'block_3' => t('Block Color Set 3'),
    'block_4' => t('Block Color Set 4'),
    'block_5' => t('Block Color Set 5'),
    'block_6' => t('Block Color Set 6'),
    'block_7' => t('Block Color Set 7'),
    'block_8' => t('Block Color Set 8'),
  ),

  'tokens' => array(

    // Typography
    'font-heading' => array(
      'label'   => t('Heading font'),
      'type'    => 'font',
      'default' => "'Playfair Display', Georgia, serif",
      'group'   => 'typography',
      'utility' => TRUE,
    ),
    'font-body' => array(
      'label'   => t('Body font'),
      'type'    => 'font',
      'default' => "'Lato', 'Helvetica Neue', Arial, sans-serif",
      'group'   => 'typography',
      'utility' => TRUE,
    ),

    // Buttons
    'button-bg' => array(
      'label'   => t('Button background'),
      'type'    => 'color',
      'default' => '#6e0e0a',
      'group'   => 'buttons',
      'utility' => TRUE,
    ),
    'button-text' => array(
      'label'   => t('Button text'),
      'type'    => 'color',
      'default' => '#ffffff',
      'group'   => 'buttons',
    ),
    'button-bg-hover' => array(
      'label'   => t('Button background (hover)'),
      'type'    => 'color',
      'default' => '#580b08',
      'group'   => 'buttons',
    ),
    'button-border-radius' => array(
      'label'   => t('Button corner radius'),
      'type'    => 'text',
      'default' => '0',
      'group'   => 'buttons',
    ),
    'button-text-transform' => array(
      'label'   => t('Button text transform'),
      'type'    => 'text',
      'default' => 'uppercase',
      'group'   => 'buttons',
    ),

    // Links
    'link-color' => array(
      'label'   => t('Link color'),
      'type'    => 'color',
      'default' => '#6e0e0a',
      'group'   => 'links',
    ),
    'link-color-hover' => array(
      'label'   => t('Link color (hover)'),
      'type'    => 'color',
      'default' => '#580b08',
      'group'   => 'links',
    ),
    'link-color-visited' => array(
      'label'   => t('Link color (visited)'),
      'type'    => 'color',
      'default' => '#551a8b',
      'group'   => 'links',
    ),
    'link-text-decoration' => array(
      'label'   => t('Link underline'),
      'type'    => 'text',
      'default' => 'none',
      'group'   => 'links',
    ),
    'link-text-decoration-hover' => array(
      'label'   => t('Link underline (hover)'),
      'type'    => 'text',
      'default' => 'underline',
      'group'   => 'links',
    ),
    'link-color-inverted' => array(
      'label'   => t('Link color (on dark backgrounds)'),
      'type'    => 'color',
      'default' => '#f0e6b8',
      'group'   => 'links',
    ),
    'color-text-default' => array(
      'label'   => t('Block text (on light backgrounds)'),
      'type'    => 'color',
      'default' => '#1a1a1a',
      'group'   => 'links',
    ),
    'color-text-inverted' => array(
      'label'   => t('Block text (on dark backgrounds)'),
      'type'    => 'color',
      'default' => '#ffffff',
      'group'   => 'links',
    ),

    // Header & Footer
    'color-primary' => array(
      'label'   => t('Primary brand color'),
      'type'    => 'color',
      'default' => '#6e0e0a',
      'group'   => 'header',
      'utility' => TRUE,
    ),
    'color-primary-text' => array(
      'label'   => t('Header & footer text'),
      'type'    => 'color',
      'default' => '#fff6ff',
      'group'   => 'header',
    ),
    'color-primary-link' => array(
      'label'   => t('Header & footer links'),
      'type'    => 'color',
      'default' => '#b2bc21',
      'group'   => 'header',
    ),

    // Hero Blocks (without images)
    'color-hero' => array(
      'label'   => t('Hero background'),
      'type'    => 'color',
      'default' => '#f0f0c9',
      'group'   => 'hero',
      'utility' => TRUE,
    ),
    'color-hero-text' => array(
      'label'   => t('Hero text'),
      'type'    => 'color',
      'default' => '#002000',
      'group'   => 'hero',
    ),
    'color-hero-link' => array(
      'label'   => t('Hero links'),
      'type'    => 'color',
      'default' => '#b2bc22',
      'group'   => 'hero',
    ),

    // Cards & Teasers
    'color-card-bg' => array(
      'label'        => t('Card background'),
      'type'         => 'color',
      'default'      => '#f8f3f3',
      'group'        => 'cards',
      'contrast_with' => 'auto',
    ),
    'card-border-radius' => array(
      'label'   => t('Corner radius'),
      'type'    => 'text',
      'default' => '0.25rem',
      'group'   => 'cards',
    ),

    // Block Color Set 1 (Soprano)
    'color-block-1' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'default'      => '#f2bb05',
      'group'        => 'block_1',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block Color Set 2 (Tenor)
    'color-block-2' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'default'      => '#124e78',
      'group'        => 'block_2',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block Color Set 3
    'color-block-3' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'default'      => '#c24608',
      'group'        => 'block_3',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block Color Set 4
    'color-block-4' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'default'      => '#4a9153',
      'group'        => 'block_4',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block Color Set 5
    'color-block-5' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'default'      => '#7b2d8b',
      'group'        => 'block_5',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block Color Set 6
    'color-block-6' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'default'      => '#1a6b6b',
      'group'        => 'block_6',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block Color Set 7
    'color-block-7' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'default'      => '#8b6d14',
      'group'        => 'block_7',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
    // Block Color Set 8
    'color-block-8' => array(
      'label'        => t('Background'),
      'type'         => 'color',
      'default'      => '#5c1a1a',
      'group'        => 'block_8',
      'utility'      => TRUE,
      'contrast_with' => 'auto',
    ),
  ),

  'schemes' => array(

    // Warm theatrical reds, gold, and navy — the signature Opera look.
    'default' => array(
      'title'  => t('Opera (default)'),
      'tokens' => array(
        'color-primary'      => '#6e0e0a',
        'color-primary-text' => '#fff6ff',
        'color-primary-link' => '#b2bc21',
        'color-hero'         => '#f0f0c9',
        'color-hero-text'    => '#ffffff',
        'color-hero-link'    => '#b2bc22',
        'color-block-1'      => '#f2bb05',
        'color-block-2'      => '#124e78',
        'color-block-3'      => '#c24608',
      ),
    ),

    // Deep navy and teal — cool and sophisticated.
    'plume' => array(
      'title'  => t('Plume'),
      'tokens' => array(
        'color-primary'      => '#1c2541',
        'color-primary-text' => '#fef3ff',
        'color-primary-link' => '#7ec8c8',
        'color-hero'         => '#e8f4f8',
        'color-hero-text'    => '#ffffff',
        'color-hero-link'    => '#1c6ea4',
        'color-block-1'      => '#94d3c9',
        'color-block-2'      => '#0b132b',
        'color-block-3'      => '#3a506b',
      ),
    ),

    // Vivid, high-saturation — bold and energetic.
    'bright' => array(
      'title'  => t('Bright'),
      'tokens' => array(
        'color-primary'      => '#c0392b',
        'color-primary-text' => '#ffffff',
        'color-primary-link' => '#f9ca24',
        'color-hero'         => '#ffeaa7',
        'color-hero-text'    => '#ffffff',
        'color-hero-link'    => '#c0392b',
        'color-block-1'      => '#f39c12',
        'color-block-2'      => '#27ae60',
        'color-block-3'      => '#2573a7',
      ),
    ),

    // Near-black backgrounds with warm muted accents — dark mode feel.
    'night' => array(
      'title'  => t('Night'),
      'tokens' => array(
        'color-primary'      => '#1a1a2e',
        'color-primary-text' => '#e0e0e0',
        'color-primary-link' => '#e94560',
        'color-hero'         => '#16213e',
        'color-hero-text'    => '#c0c0c0',
        'color-hero-link'    => '#e94560',
        'color-block-1'      => '#0f3460',
        'color-block-2'      => '#533483',
        'color-block-3'      => '#232020',
      ),
    ),
  ),
);
