IRRELEVANT FOR GNOME 3.22.3+
============================

Starting from gnome 3.22.3 there is official dark variant of Adwaita theme for gtk-2

Adwaita-dark-gtk2
=================

This is clone of gnome3 Adwaita theme
It is tuned to work with GTK-2 application exactly as with GTK-3

INSTALLATION
=================

#### 1. Install theme itself

* Install the theme in either /usr/share/themes, or in your home directory, in ~/.local/share/themes and ~/.themes (see http://worldofgnome.org/gtk-theme-ing-issue-in-gnome-3-10/ for an explaination 
  of why both are required)
* go to the desired theme folder:
`$ cd /usr/share/themes`
* clone theme's repo:
`$ git clone <URI> Adwaita-dark`
* e.g.:
  `$ git clone https://github.com/<github-user>/Adwaita-dark-gtk2 Adwaita-dark`
  * You'll have to use sudo here if installing in a system-wide location
* for versions of gnome-shell <= 3.12 switch to 3.12 tag:
`$ sudo git checkout gnome_3.12`
* launch gnome-tweak-tool
* go to Appearance section
* change "Window" and "GTK+" themes to Adwaita-dark

#### 2. Gnome 3.18+
Unfurtunately, for gnome 3.18+ you have to modify Adwaita theme itself to make it work.
```
$ cd /usr/share/themes/Adwaita
# cp gtk-2.0 gtk-2.0-bkp
# cp -R ../Adwaita-dark/gtk-2.0 ./
```
Teh best way is to create a user theme folder under `~/.themes`:
```
$ mkdir -p ~/.themes/Adwaita
$ cd ~/.themes/Adwaita
# ln -s /usr/share/themes/Adwaita-dark/gtk-2.0 .
```
And use Adwaita as your theme instead of Adwaita-dark

#### 3. Configure gnome apps
##### Gnome Terminal
* Open gnome-terminal
* go to Edit->Preferences menu
* select "Use dark theme variant" checkbox

##### Gedit
* Open gedit
* go to Preferences (by clicking on the name of application in the top panel of gnome-shell)
* Open tab "Font and Colors"
* Select any dark theme you like (I prefer Oblivion)

NOTES ABOUT UTILITIES
=================

NOTE: these utilities appear to be at least partly broken on gtk
3.18+.

gtk-color-export relies on getting a single background color from the
running gtk3 theme to replicate in a gtk2 gtkrc. Unfortunately, the
concept of a single "background color" doesn't exist in modern gtk3.

Per the documentation of
https://developer.gnome.org/gtk3/stable/GtkStyleContext.html#gtk-style-context-get-background-color:

"This function is far less useful than it seems, and it should not be
used in newly written code. CSS has no concept of "background color",
as a background can be an image, or a gradient, or any other pattern
including solid colors."

Current gtk actually returns solid black when asked for the background
theme of an element here, suggesting this may be the end of the road
for automatic synchronization of colors.

These shouldn't be relevant out-of-the box, but may be important if
the Adwaita theme changes in some way.

sync.sh:
* sync.sh performs 2 tasks to synchronize properties from Adwaita to this theme:
    1. It copies Adwaita's index.theme, modifying the appropriate values to refer to this theme's components
    2. It uses gtk-color-export (described below) to read the color scheme of this theme's gtk3 variant, and write it into the gtk2 variant

gtk-color-export/:

* gtk-color-export is a very small windowless gtk3 application, for
  the express purpose of reading the color scheme out out of a gtk3
  theme, and output a "gtk-color-scheme =" line suitable for inclusion
  in a gtk2 theme. It will be called automatically as a part of
  executing sync.sh, using this theme's gtk3 version as the theme to
  extract a scheme from.


AUTHORS
=================
- originally cloned by Roi M (https://plus.google.com/+RoiMMrNucky/posts/KsybAs8Htgc)
- tuned and adapted for gnome 3.12-3.20 by Alexey M (https://github.com/axxapy)
- further tuned by Jeremy N (https://plus.google.com/102019683200554479931)
