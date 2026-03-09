# Opera

Opera is a Backdrop CMS theme designed for sites that use stacked, full-width panels on the
front page with alternating background colors. It is approachable for people new to Backdrop
and offers significant customization through the admin UI — no CSS required.

![A screenshot of a site with stacked full width blocks and hero images.](https://simplo.site/files/opera-opera.png)

## Status

Opera 2.x is under active development. The theme is functional and suitable for testing,
feedback, and building on. Not recommended for production sites until a stable release is
tagged. Bug reports, feature requests, and pull requests are welcome.

## Who is this theme for?

Opera is a good fit if you want to:

- Build a front page with full-width stacked content panels in different background colors
- Customize colors, fonts, buttons, and links through the admin UI without writing CSS
- Use a theme that works well out of the box for a non-profit, arts organization, or
  community site

## Key features

### Stacked full-width blocks
The signature Opera layout uses Backdrop's Boxton layout on the front page. Blocks in the
content region extend the full width of the screen with their own background colors. The
first and last blocks are always white; middle blocks cycle through your chosen color sets.

### Design Tokens integration
Opera uses the [Design Tokens](https://backdropcms.org/project/design_tokens) module to
manage all visual configuration. From a single admin page you can change:

- **Color sets** — background colors for the header, hero blocks, and each cycling block
  set (up to 8 sets). Text and link colors are calculated automatically based on whether
  the background is light or dark — you only set the background.
- **Fonts** — heading and body font families, with Google Fonts support built in
- **Buttons** — background, text, hover, border radius, and text transform
- **Links** — color, hover color, visited color, and underline behavior
- **Global text colors** — inverted (light) and default (dark) text colors used on colored
  blocks

Changes are reflected in a live preview alongside the form — no page reload required.

### Preset color schemes
Opera ships with four preset color schemes: **Opera** (deep red and gold), **Plume**
(navy and teal), **Bright** (vivid primaries), and **Night** (dark mode feel). Applying
a scheme populates all color fields at once. Modifying any value after applying a scheme
marks it as Custom.

### Accessibility
The Design Tokens admin page shows WCAG contrast ratio badges next to each text color
field, updated in real time as colors change. Text and link colors for colored blocks are
auto-calculated using the WCAG luminance threshold so they always meet AA contrast
requirements against their background.

## Requirements

- Backdrop CMS 1.x
- [Design Tokens](https://backdropcms.org/project/design_tokens) module
- `design_tokens_color` and `design_tokens_font` sub-modules (included with Design Tokens)

## Setup

1. Enable the Design Tokens module and its `design_tokens_color` and `design_tokens_font`
   sub-modules at **Functionality > Modules**.
2. Set Opera as your default theme at **Appearance**.
3. Configure your site's appearance at **Appearance > Design Tokens > Opera**.
4. Set your front page to use the **Boxton** layout at **Structure > Layouts**.
5. Add blocks to the Boxton layout's content region — they will automatically receive
   cycling background colors.

## Recommended modules

The Opera theme settings page (**Appearance > Settings > Opera**) includes a list of
modules that pair well with Opera, with direct links to install them. These include:

- **Configurable Block Styles** — apply style presets to individual blocks
- **Nice Messages** — improved styling for status and error messages
- **Tab Icons** — icons on admin task tabs
- **Custom Breadcrumbs** — control over the breadcrumb trail

## Layout details

### Front page (Boxton layout)
- First and last content blocks: always white background, standard link colors
- Middle content blocks: cycle through your configured color sets (2–8 sets, configurable
  in theme settings)
- Color sequencing is controlled by the **Color sequence length** setting

### Block color sets
Each color set is defined by a single background color. Text and link colors are
automatically computed from the background's luminance — dark backgrounds get light text
and light links; light backgrounds get dark text and standard body link colors.

### Hero blocks
Blocks using the Hero block type display with a minimum height of 450px. The hero region
uses its own color set separate from the cycling block colors.

## Sub-theming

Opera is suitable as a base for a sub-theme. A sub-theme can:

- Override any template in `templates/`
- Add its own `tokens.inc` to extend or replace Opera's Design Token definitions
- Override CSS in component files under `css/component/`

## Contributing

The Opera theme is maintained at https://github.com/backdrop-contrib/opera.

Notes About Use of AI
---------------------

This theme was developed with significant assistance from AI tools (specifically Claude by
Anthropic). AI was used to generate code, plan features, and make iterative improvements
throughout development. We welcome feedback.

Pull requests and issue reports are welcome.

LICENSE
---------------

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.

CURRENT MAINTAINERS
---------------

- Tim Erickson (https://github.com/stpaultim/)

CREDITS
---------------

Development supported by Simplo (by Triplo) - https://simplo.site
