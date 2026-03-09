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
    'typography' => array(
      'label' => t('Typography'),
      'description' => t('Fonts used for headings and body text across the site.'),
    ),
    'buttons' => array(
      'label' => t('Buttons'),
      'description' => t('Controls the appearance of primary buttons and form submit buttons across the site.'),
    ),
    'links' => array(
      'label' => t('Links'),
      'description' => t('Controls the color and underline behavior of body links — links in the main content area, not within colored header or block regions.'),
    ),
    'header' => array(
      'label' => t('Header & Footer'),
      'description' => t('Colors for the site header and footer regions, including the site name, navigation links, and footer text.'),
    ),
    'hero' => array(
      'label' => t('Hero Blocks'),
      'description' => t('Colors for hero blocks that do not have a custom background image. These appear as a colored banner at the top of the page.'),
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
      'default' => "'Merriweather', Georgia, serif",
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
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#6e0e0a',
      'group'   => 'buttons',
      'utility' => TRUE,
    ),
    'button-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#ffffff',
      'group'   => 'buttons',
    ),
    'button-bg-hover' => array(
      'label'   => t('Background (hover)'),
      'type'    => 'color',
      'default' => '#580b08',
      'group'   => 'buttons',
    ),
    'button-border-radius' => array(
      'label'   => t('Border radius'),
      'type'    => 'text',
      'default' => '0',
      'group'   => 'buttons',
    ),
    'button-text-transform' => array(
      'label'   => t('Text transform'),
      'type'    => 'text',
      'default' => 'uppercase',
      'group'   => 'buttons',
    ),

    // Links
    'link-color' => array(
      'label'   => t('Color'),
      'type'    => 'color',
      'default' => '#6e0e0a',
      'group'   => 'links',
    ),
    'link-color-hover' => array(
      'label'   => t('Color (hover)'),
      'type'    => 'color',
      'default' => '#580b08',
      'group'   => 'links',
    ),
    'link-color-visited' => array(
      'label'   => t('Color (visited)'),
      'type'    => 'color',
      'default' => '#551a8b',
      'group'   => 'links',
    ),
    'link-text-decoration' => array(
      'label'   => t('Underline'),
      'type'    => 'text',
      'default' => 'underline',
      'group'   => 'links',
    ),
    'link-text-decoration-hover' => array(
      'label'   => t('Underline (hover)'),
      'type'    => 'text',
      'default' => 'underline',
      'group'   => 'links',
    ),

    // Header & Footer
    'color-primary' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#6e0e0a',
      'group'   => 'header',
      'utility' => TRUE,
    ),
    'color-primary-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#fff6ff',
      'group'   => 'header',
    ),
    'color-primary-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'default' => '#b2bc21',
      'group'   => 'header',
    ),

    // Hero Blocks (without images)
    'color-hero' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#f0f0c9',
      'group'   => 'hero',
      'utility' => TRUE,
    ),
    'color-hero-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#002000',
      'group'   => 'hero',
    ),
    'color-hero-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'default' => '#b2bc22',
      'group'   => 'hero',
    ),

    // Block Color Set 1 (Soprano)
    'color-block-1' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#f2bb05',
      'group'   => 'block_1',
      'utility' => TRUE,
    ),
    'color-block-1-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#002002',
      'group'   => 'block_1',
    ),
    'color-block-1-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'default' => '#b2bc23',
      'group'   => 'block_1',
    ),

    // Block Color Set 2 (Tenor)
    'color-block-2' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#124e78',
      'group'   => 'block_2',
      'utility' => TRUE,
    ),
    'color-block-2-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#fff4ff',
      'group'   => 'block_2',
    ),
    'color-block-2-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'default' => '#b2bc24',
      'group'   => 'block_2',
    ),

    // Block Color Set 3
    'color-block-3' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#d74e09',
      'group'   => 'block_3',
      'utility' => TRUE,
    ),
    'color-block-3-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#fffff5',
      'group'   => 'block_3',
    ),
    'color-block-3-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'default' => '#b2bc25',
      'group'   => 'block_3',
    ),

    // Block Color Set 4
    'color-block-4' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#4a9153',
      'group'   => 'block_4',
      'utility' => TRUE,
    ),
    'color-block-4-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#ffffff',
      'group'   => 'block_4',
    ),
    'color-block-4-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'default' => '#c8f5cb',
      'group'   => 'block_4',
    ),

    // Block Color Set 5
    'color-block-5' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#7b2d8b',
      'group'   => 'block_5',
      'utility' => TRUE,
    ),
    'color-block-5-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#ffffff',
      'group'   => 'block_5',
    ),
    'color-block-5-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'default' => '#f0c8f5',
      'group'   => 'block_5',
    ),

    // Block Color Set 6
    'color-block-6' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#1a6b6b',
      'group'   => 'block_6',
      'utility' => TRUE,
    ),
    'color-block-6-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#ffffff',
      'group'   => 'block_6',
    ),
    'color-block-6-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'default' => '#c8f5f5',
      'group'   => 'block_6',
    ),

    // Block Color Set 7
    'color-block-7' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#8b6d14',
      'group'   => 'block_7',
      'utility' => TRUE,
    ),
    'color-block-7-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#ffffff',
      'group'   => 'block_7',
    ),
    'color-block-7-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'default' => '#f5e6c8',
      'group'   => 'block_7',
    ),

    // Block Color Set 8
    'color-block-8' => array(
      'label'   => t('Background'),
      'type'    => 'color',
      'default' => '#5c1a1a',
      'group'   => 'block_8',
      'utility' => TRUE,
    ),
    'color-block-8-text' => array(
      'label'   => t('Text'),
      'type'    => 'color',
      'default' => '#f5f5f5',
      'group'   => 'block_8',
    ),
    'color-block-8-link' => array(
      'label'   => t('Links'),
      'type'    => 'color',
      'default' => '#f5c8c8',
      'group'   => 'block_8',
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
        'color-hero-text'    => '#002000',
        'color-hero-link'    => '#b2bc22',
        'color-block-1'      => '#f2bb05',
        'color-block-1-text' => '#002002',
        'color-block-1-link' => '#b2bc23',
        'color-block-2'      => '#124e78',
        'color-block-2-text' => '#fff4ff',
        'color-block-2-link' => '#b2bc24',
        'color-block-3'      => '#d74e09',
        'color-block-3-text' => '#fffff5',
        'color-block-3-link' => '#b2bc25',
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
        'color-hero-text'    => '#0d1b2a',
        'color-hero-link'    => '#1c6ea4',
        'color-block-1'      => '#94d3c9',
        'color-block-1-text' => '#001012',
        'color-block-1-link' => '#1c2541',
        'color-block-2'      => '#0b132b',
        'color-block-2-text' => '#fef4ff',
        'color-block-2-link' => '#7ec8c8',
        'color-block-3'      => '#3a506b',
        'color-block-3-text' => '#f0faff',
        'color-block-3-link' => '#7ec8c8',
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
        'color-hero-text'    => '#2d3436',
        'color-hero-link'    => '#c0392b',
        'color-block-1'      => '#f39c12',
        'color-block-1-text' => '#1a1a1a',
        'color-block-1-link' => '#c0392b',
        'color-block-2'      => '#27ae60',
        'color-block-2-text' => '#ffffff',
        'color-block-2-link' => '#f9ca24',
        'color-block-3'      => '#2980b9',
        'color-block-3-text' => '#ffffff',
        'color-block-3-link' => '#f9ca24',
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
        'color-block-1-text' => '#e0e0e0',
        'color-block-1-link' => '#e94560',
        'color-block-2'      => '#533483',
        'color-block-2-text' => '#f0f0f0',
        'color-block-2-link' => '#e94560',
        'color-block-3'      => '#232020',
        'color-block-3-text' => '#d0d0d0',
        'color-block-3-link' => '#e94560',
      ),
    ),
  ),
);
