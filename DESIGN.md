# Opera — Design Principles

This document records the design decisions and conventions established for the Opera theme.
Its purpose is to keep future development consistent and to explain *why* things are done
the way they are, not just *what* they do.

---

## Visual hierarchy by audience

The most important principle in Opera's UI is distinguishing controls by who sees them.

### Admin-only controls
Elements only visible to logged-in editors (admin tabs, comment delete/edit/reply, book
"Add child page"/"Reorder book") use **hardcoded neutral grays — never theme colors**.

- Active state: `background: #444; color: #fff`
- Hover state: `background: var(--color-card-bg); border-color: #999; color: #333`
- Default state: `border: 1px solid #bbb; color: #555; background: transparent`

The hover state uses `--color-card-bg` (a 5% primary tint into white) rather than a
hardcoded grey. At that opacity the tint is near-invisible and will never read as a
theme color — it just provides a subtle lift. Active and default states remain fully
hardcoded.

**Why:** Admin controls should feel like system UI, not site content. A site architect
who changes `--color-primary` to blue should not accidentally make "DELETE" look like a
tag. Neutral gray is visually subordinate and universally understood as interface chrome.

### Public-facing navigation
Controls visible to all visitors (book prev/next, pagers, Read More) use **Design Token
variables** so they automatically respect the site's configured color scheme.

- Use `var(--button-bg)`, `var(--button-text)`, `var(--button-bg-hover)`
- Use `var(--button-border-radius)` for consistent shape

**Why:** These are part of the front-end experience. A visitor interacting with book
navigation should see the same visual language as other buttons on the site.

---

## Shape as semantic signal

Shapes carry meaning consistently across Opera. Do not mix them.

| Shape | Border radius | Used for |
|---|---|---|
| **Pill** | `2em` | Content labels only (taxonomy tags) |
| **Rectangular** | `0.25rem` | All actionable controls (buttons, admin tabs, nav) |

**Why:** Pills say "this is a label describing content." Rectangles say "this is something
you can do." A site visitor who sees a pill-shaped "Edit" button will be confused about
whether it's a tag or an action. Keep the shapes exclusive to their roles.

---

## Token usage

### Use tokens for public-facing UI
Anything a regular visitor interacts with should pull from Design Tokens:
- `--button-bg`, `--button-text`, `--button-bg-hover`, `--button-border-radius`
- `--color-primary`, `--color-primary-text`
- `--color-card-bg`, `--color-surface-mid` (surface tints derived from primary)

### Never use tokens for admin-only UI
Admin controls use hardcoded values for active/default states. This is intentional —
they must not shift when a site architect changes the color scheme.

### Surface tint tokens
`--color-card-bg` and `--color-surface-mid` are derived from `--color-primary` via
CSS `color-mix()` and should be used instead of hardcoded greys (`#f5f5f5`, `#dee2ea`,
`#d0d0d0`, etc.) for all backgrounds, borders, and hover states across the theme.

| Token | Mix | Used for |
|---|---|---|
| `--color-card-bg` | 5% primary + white | Card backgrounds, table headers, form surfaces |
| `--color-surface-mid` | 12% primary + white | Borders, hover states, sidebar backgrounds |

`--color-surface-mid` lives in `opera-derived-variables.css` (never removed by Design
Tokens module). `--color-card-bg` is also a registered token so admins can override it.

### Never use hardcoded greys for surfaces
Replace `#f5f5f5`, `#dee2ea`, `#bbbbbb`, `#f0f0f0`, `#d0d0d0`, `#e5e5e6` with the
appropriate surface token. The only exception is admin-only active/default states.

### `!important` on color overrides
`front.css` block link selectors can have very high specificity (up to 7 chained
classes). When tag pills or button colors are not applying inside front-page colored
blocks, `!important` on the `color` property is the correct fix — not adding more
selector weight.

---

## Split header architecture

Opera uses a two-bar header: a **logo bar** above and a **nav bar** below.

- **Logo bar** — background: `--color-header-bg` (white by default). Contains the site name/logo and utility links.
- **Nav bar** — background: `--color-primary`. Contains the main navigation menu. Also matches the footer color, so nav and footer visually bookend the content.

**How it works:**

The layout templates use `<div class="l-header-inner">` with **no container class**. This makes all blocks in the header region naturally full-width. Each block's content is constrained by:

```css
.l-header .block--inner-wrapper {
  max-width: 1200px;
  margin-left: auto;
  margin-right: auto;
  padding-left: 15px;
  padding-right: 15px;
}
```

The nav bar color is applied directly to `.block-system-main-menu` in `header.css`. Because that block is full-width (no outer container), its background extends edge-to-edge.

**Critical:** Never add `container` or `container-fluid` back to `.l-header-inner`. That would constrain both blocks together and break the two-bar split.

Both colors are Design Token–controlled: `color-header-bg` / `color-header-text` (logo bar) and `color-primary` / `color-primary-text` / `color-primary-link` (nav + footer).

---

## Container nesting rule

Backdrop's Bootstrap grid gives `.container` and `.container-fluid` `padding: 0 15px`.
When a `.container` is nested inside another `.container`, the padding stacks and content
appears indented relative to other page elements.

**Rule:** Any `.container` nested inside an already-padded container must have its own
`padding-left` and `padding-right` zeroed.

Established patterns:
```css
/* Views blocks nested inside a container region */
.view.container { padding-left: 0; padding-right: 0; }

/* Footer: all nested containers (blocks, flexible layout rows) */
.l-footer-inner .container,
.l-footer-inner .container-fluid { padding-left: 0; padding-right: 0; }
```

Note: The header region no longer uses a container on `.l-header-inner` — each block
carries its own constraint via `.l-header .block--inner-wrapper`. See split header section above.

When adding new regions or block types, check whether content aligns with the page
title before shipping. The browser devtools left-edge coordinate is the quickest check:
page title, main content, and footer content should all share the same `left` value.

---

## CSS conventions for site architects

### Tag-style pill lists in Views blocks

Taxonomy term reference fields on nodes automatically receive pill badge styling.

For a custom Views block that lists tags or terms, add the CSS class `tag-list` in the
view configuration (*Advanced → CSS class*). Opera will apply the same pill treatment.

The built-in Tags view (`view-tags`) is also supported automatically.

---

## Breadcrumb

Flexbox `ol`, `›` separator via `li + li::before`, primary-color links. The last item
(current page) is muted grey with `pointer-events: none` — it's where you are, not a
destination. See `css/component/breadcrumb.css`.

---

## Search results

`.search-results` uses the card treatment (`--color-card-bg` background, border,
border-radius) matching teasers for visual consistency. The counter number is generated
via CSS `counter()` + `::before` (absolutely positioned in the left gutter), sized and
coloured to match the reduced title. `.search-info` meta line uses small muted text with
the username in primary color. See `css/component/search.css`.

---

## Blockquote and pre/code

**Blockquote**: primary-color left border (0.3rem), 4% primary background tint, italic
body text. A large decorative `"` quote mark is placed via `::before` using the heading
font at 25% opacity — Playfair Display makes it look editorial. `<cite>` renders as
`— attribution` in small muted text.

**Pre/code blocks**: same border weight and background tint as blockquote for visual
family. `pre` has `overflow-x: auto` to prevent layout overflow. Inline `code` uses
`--color-card-bg` background with `--color-surface-mid` border.

---

## Comment structure note

Backdrop's comment template (`comment.tpl.php`) outputs:
```
article.comment
  h3.comment-title > a.permalink
  footer > p.submitted + a.permalink
  div.content
  ul.links.inline  ← delete / edit / reply (admin only)
```

The `ul.links.inline` links are admin-only and styled as rectangular ghost buttons
(neutral gray, no theme colors). See `css/component/comment.css`.

---

## Book module

Book navigation (`nav.book-navigation`) contains two distinct things:

1. **`.book-pager`** — prev/up/next for readers. Uses button tokens. Each `li` has
   `flex: 1` so a single item (e.g. only "next" on the first page) positions correctly
   via `text-align` rather than defaulting to the flex start.

2. **`.links.inline`** on `.node-book` — "Add child page" and "Reorder book". Admin-only.
   Styled as rectangular ghost buttons (neutral gray).
