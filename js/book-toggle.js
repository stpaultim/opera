/**
 * @file
 * Collapsible book navigation sidebar.
 *
 * Walks the book navigation block, injects a toggle <button> before any link
 * whose <li> has a child <ul>, and wires the button to expand/collapse that
 * branch by toggling an `is-open` class on the parent <li>. Items in the
 * active trail start expanded; everything else starts collapsed. Works in
 * tandem with the rules in css/component/book.css.
 *
 * No-JS fallback: the tree is rendered fully expanded by the theme preprocess
 * hook, so visitors without JavaScript still see every page.
 */
(function ($, Backdrop) {
  'use strict';

  Backdrop.behaviors.operaBookToggle = {
    attach: function (context) {
      var menus = context.querySelectorAll(
        '.book-navigation--collapsible .menu, .block-book-navigation .menu'
      );
      Array.prototype.forEach.call(menus, function (menu) {
        if (menu.classList.contains('is-collapsible')) {
          return;
        }
        menu.classList.add('is-collapsible');

        var items = menu.querySelectorAll('li');
        Array.prototype.forEach.call(items, function (li) {
          var childList = li.querySelector(':scope > ul');
          if (!childList) {
            return;
          }
          var link = li.querySelector(':scope > a');
          if (!link) {
            return;
          }

          // Active trail items (and their ancestors) start expanded; all
          // other branches start collapsed.
          var startsOpen =
            li.classList.contains('active-trail') ||
            !!li.querySelector('.active-trail') ||
            !!li.querySelector('a.active');
          if (startsOpen) {
            li.classList.add('is-open');
          }

          var btn = document.createElement('button');
          btn.type = 'button';
          btn.className = 'book-toggle';
          btn.setAttribute(
            'aria-label',
            Backdrop.t('Toggle @title', { '@title': link.textContent.trim() })
          );
          btn.setAttribute('aria-expanded', startsOpen ? 'true' : 'false');
          btn.innerHTML = '<span class="book-toggle__caret" aria-hidden="true"></span>';

          btn.addEventListener('click', function (event) {
            event.preventDefault();
            event.stopPropagation();
            var open = li.classList.toggle('is-open');
            btn.setAttribute('aria-expanded', open ? 'true' : 'false');
          });

          li.insertBefore(btn, link);
        });
      });
    }
  };
})(jQuery, Backdrop);
