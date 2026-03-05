<?php
/**
 * @file
 * Opera theme implementation to display the maintenance page.
 *
 * Uses Opera's header classes so the site color scheme applies automatically.
 *
 * Available variables:
 * - $base_path: The base URL path of the Backdrop installation.
 * - $front_page: The URL of the home page.
 * - $logo: The path to the logo image.
 * - $site_name: The name of the site.
 * - $site_slogan: The site slogan.
 * - $head_title: The title of the page.
 * - $title: The page title.
 * - $content: The main content of the page.
 * - $messages: Status/warning/error messages.
 *
 * @see template_preprocess_maintenance_page()
 */
?>
<!DOCTYPE html>
<html<?php print backdrop_attributes($html_attributes); ?>>

<head>
  <?php print backdrop_get_html_head(); ?>
  <title><?php print $head_title; ?></title>
  <?php print backdrop_get_css(); ?>
  <?php print backdrop_get_js(); ?>
</head>

<body class="<?php print implode(' ', $classes); ?>">

  <div class="l-header" role="banner">
    <div class="l-header-inner maintenance-header-inner">
      <?php if ($logo || $site_name || $site_slogan): ?>
        <div class="header-identity-wrapper">
          <?php if ($logo || $site_name): ?>
            <div class="header-site-name-wrapper">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header-site-name-link" rel="home">
                <?php if ($logo): ?>
                  <div class="header-logo-wrapper">
                    <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header-logo" />
                  </div>
                <?php endif; ?>
                <?php if ($site_name): ?>
                  <strong><?php print $site_name; ?></strong>
                <?php endif; ?>
              </a>
            </div>
          <?php endif; ?>
          <?php if ($site_slogan): ?>
            <div class="header-site-slogan"><?php print $site_slogan; ?></div>
          <?php endif; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>

  <div class="maintenance-content">
    <div class="maintenance-container">
      <div class="maintenance-image" role="img" aria-label="<?php print t('A dragon singing opera'); ?>">
        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 260 210" fill="none">
          <!-- Tail -->
          <path d="M158 168 C188 180 208 163 203 146 C198 130 184 137 188 124" stroke="#111" stroke-width="15" stroke-linecap="round"/>
          <!-- Left wing -->
          <path d="M68 126 C42 96 14 80 20 54 C44 70 68 98 73 120 Z" fill="#1a1a1a"/>
          <path d="M68 126 C42 96 14 80 20 54" stroke="#2a2a2a" stroke-width="1.5"/>
          <!-- Right wing -->
          <path d="M172 126 C198 96 226 80 220 54 C196 70 172 98 167 120 Z" fill="#1a1a1a"/>
          <path d="M172 126 C198 96 226 80 220 54" stroke="#2a2a2a" stroke-width="1.5"/>
          <!-- Body -->
          <ellipse cx="120" cy="160" rx="58" ry="46" fill="#111"/>
          <!-- Belly -->
          <ellipse cx="120" cy="168" rx="37" ry="29" fill="#2a2a2a"/>
          <!-- Back spikes -->
          <path d="M97 112 L91 90 L100 110 Z M112 105 L107 81 L116 103 Z M128 105 L133 81 L124 103 Z M143 112 L149 90 L140 110 Z" fill="#2a2a2a"/>
          <!-- Neck -->
          <ellipse cx="120" cy="118" rx="27" ry="36" fill="#111"/>
          <!-- Head -->
          <ellipse cx="120" cy="82" rx="40" ry="34" fill="#111"/>
          <!-- Brow ridges -->
          <path d="M90 69 C96 62 107 61 113 66" stroke="#2a2a2a" stroke-width="4" stroke-linecap="round"/>
          <path d="M127 66 C133 61 144 62 150 69" stroke="#2a2a2a" stroke-width="4" stroke-linecap="round"/>
          <!-- Eyes: amber with dark slit pupils -->
          <circle cx="102" cy="74" r="10" fill="white"/>
          <circle cx="103" cy="74" r="6.5" fill="#e8a000"/>
          <ellipse cx="104" cy="74" rx="2.5" ry="4" fill="#111"/>
          <circle cx="138" cy="74" r="10" fill="white"/>
          <circle cx="139" cy="74" r="6.5" fill="#e8a000"/>
          <ellipse cx="140" cy="74" rx="2.5" ry="4" fill="#111"/>
          <!-- Snout -->
          <ellipse cx="120" cy="100" rx="26" ry="15" fill="#1a1a1a"/>
          <!-- Open mouth: singing! -->
          <path d="M97 100 Q120 128 143 100" fill="#8b0000"/>
          <!-- Teeth -->
          <path d="M97 100 L101 113 L107 100 L112 113 L118 100 L123 113 L129 100 L134 113 L139 100 L143 100" fill="white"/>
          <!-- Tongue -->
          <path d="M113 118 Q120 128 127 118" fill="#cc1100"/>
          <!-- Nostrils -->
          <ellipse cx="113" cy="96" rx="3" ry="2" fill="#2a2a2a"/>
          <ellipse cx="127" cy="96" rx="3" ry="2" fill="#2a2a2a"/>
          <!-- Horns -->
          <path d="M103 54 C101 42 95 26 97 16 C101 29 108 44 109 54 Z" fill="#111"/>
          <path d="M137 54 C139 42 145 26 143 16 C139 29 132 44 131 54 Z" fill="#111"/>
          <!-- Musical notes -->
          <text x="162" y="66" font-family="Georgia,serif" font-size="30" fill="#111">&#9834;</text>
          <text x="186" y="42" font-family="Georgia,serif" font-size="22" fill="#333">&#9835;</text>
          <text x="166" y="36" font-family="Georgia,serif" font-size="16" fill="#555">&#9833;</text>
        </svg>
      </div>

      <main role="main">
        <?php if (!empty($title)): ?>
          <h1><?php print $title; ?></h1>
        <?php endif; ?>
        <?php if (!empty($messages)): print $messages; endif; ?>
        <?php print $content; ?>
      </main>
    </div>
  </div>

</body>
</html>
