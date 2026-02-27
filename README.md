A companion font library for [roo_display](http://github.com/dejwk/roo_display). Meant to be used in addition to roo_fonts_basic, for
UIs with [Material Design](https://m3.material.io/blog/design-material-theme-type) look and feel (although using NotoSans, rather than Roboto).

Contains the following fonts from the NotoSans family:

*  Regular: 9, 11, 14, 16, 20, 21, 24, 26, 28, 32, 34, 36, 48, 51, 68, 72, 96
*  Light: 45, 60, 72, 90, 96, 120, 144, 192
*  Medium: 11, 14, 15, 20, 21, 28, 30, 40

All fonts are also provided in the 'condensed' variant.

They are intended for use for theming at 4 different zoom levels:

200%

* H1: Light 192
* H2: Light 120
* H3: Regular 96
* H4: Regular 68
* H5: Regular 48
* H6: Medium 40
* Subtitle 1: Regular 32
* Subtitle 2: Medium 28
* Body 1: Regular 32
* Body 2: Regular 28
* Button: Medium 28
* Caption: Regular 24
* Overline: Regular 20

150%

* H1: Light 144
* H2: Light 90
* H3: Regular 72
* H4: Regular 51
* H5: Regular 36
* H6: Medium 30
* Subtitle 1: Regular 24
* Subtitle 2: Medium 21
* Body 1: Regular 24
* Body 2: Regular 21
* Button: Medium 21
* Caption: Regular 18*
* Overline: Regular 15*

100%

* H1: Light 96
* H2: Light 60
* H3: Regular 48
* H4: Regular 34
* H5: Regular 24
* H6: Medium 20
* Subtitle 1: Regular 16
* Subtitle 2: Medium 14
* Body 1: Regular 16
* Body 2: Regular 14
* Button: Medium 14
* Caption: Regular 12*
* Overline: Regular 10*

75%

* H1: Light 72
* H2: Light 45
* H3: Regular 36
* H4: Regular 26
* H5: Regular 18*
* H6: Medium 15
* Subtitle 1: Regular 12*
* Subtitle 2: Medium 11
* Body 1: Regular 12*
* Body 2: Regular 11
* Button: Medium 11
* Caption: Regular 9
* Overline: Regular 8*

Suggested zoom selection per DPI level:

* 200% for DPI >= 270
* 150% for DPI >= 200
* 100% for DPI >= 135
* 75% otherwise

*) Sizes marked with * are not included in this library. For Regular, use
	the roo_display builtin fonts; for Condensed, use [roo_fonts_basic](http://github.com/dejwk/roo_fonts_basic).
