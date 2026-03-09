# Opera

This is intended to be a contrib theme based upon some specific designs developed for a non-profit client. 
The intent is to create a contrib theme and then sub-theme for our specific client.
Our goal will be to have the main theme do as much of the work as possible, yet remain flexible enough to
be used by others in a variety of use cases. 

The intention for this theme is that it is usable out of the box. This is not a theming framework, it should
be easy to use for end users with configuration options in the UI. However, it should also be well documented 
for users who wish to sub-theme it. 

# Status

This theme is still fairly raw, but we hope to make steady progress over the next few weeks. It's not too early
to test it, make feature requests, file bug reports, and submit PRs. 

# Who is this theme for?

The primary audience of this theme are individuals looking for a flexible theme that will accomodate a variety
of color schemes without the need to write any custom css. This theme will be most useful for users looking 
to make heavy use of background colors and/or hero images in blocks on the front page. 

This theme is good for building front page layouts (eventually we may provide options for other pages as well) 
that look like this:

![A screenshot of a site with stacked full width blocks and hero images.](https://simplo.site/files/opera-opera.png)

# Goals

- Instructions for sub-theming
- Compatible with color module
- Provide default CSS files in simple CSS
- Provide a SASS starter kit for sub-theming
- Provide a straight CSS starter kit for sub-theming
- Experiment with providing support for [Config Recipes](https://github.com/backdrop-contrib/config_recipes) within this theme. 

# Instructions

One of the primary features of the Opera theme is the ability to build a layout using full width blocks 
with backgroud images and/or colors stacked one above the other. full-with layouts on the front page 
with To leverage these features you will need to follow the following instructions:

1) Be sure to use the Boxton layout on front page (for full width blocks with background colors)
2) Any blocks placed in content region of front page will automatically get assigned background colors based upon site color scheme
3) Choose from pre-defined color schemes in theme settings (or use color module to define your own)

If you use the Boxton layout for your front page. The following will be true:
1) The first and last block in the content region will have a white background with black text. 
2) Any blocks in the content region between the first and last, will cycle through a list of three colors schemes set in the themes settings.
3) Any hero blocks will start out with min-height of 450px.

# Features implemented so far

Please, feel free to provide feedback on these features and/or the implementation.

1) This theme has a the following template to override Boxton when it is on the front page. The layout--boxton--front.tpl.php removes the container class from the content region allowing blocks to spread out the full width of the screen. An override of block.tpl.php puts the container class into the title and content of any block found on the front page. 
2) We have provided template files for all of the core templates that move the top region above the default locaton for title and tabs. This puts the default position for breadcrumbs above the page title and tabs. We now have the possibility to make other adjustments in all core layouts. 
3) So far, this theme inherits a lot of it's default styling from Basis and Tatsu, but with improvements. That may change over time.  

Here is a 30 minute video discussion of several members of the Backdrop CMS community talking about how to build a contrib theme like this one. https://youtu.be/BeEzXuwLxo8 

Notes About Use of AI
---------------------

This theme was developed with significant assistance from AI tools (specifically Claude by Anthropic). AI was used to generate code, plan features, and make iterative improvements throughout development. We welcome feedback. 

Pull requests and issue reports are welcome.

LICENSE
---------------    

This project is GPL v2 software. See the LICENSE.txt file in this directory 
for complete text.

CURRENT MAINTAINERS
---------------    

- Tim Erickson (https://github.com/stpaultim/)

CREDITS   
--------------- 

Development supported by Simplo (by Triplo) - https://simplo.site
