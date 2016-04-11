Adwaita-dark-gtk2
=================

This is clone of gnome3 Adwaita theme
It is tuned to work with GTK-2 application exactly as with GTK-3

INSTALLATION
=================

#### 1. Install theme itself

* go to the themes folder:
`$ cd /usr/share/themes`
* clone theme's repo:
`$ sudo git clone https://github.com/axxapy/Adwaita-dark-gtk2.git Adwaita-dark`
* for versions of gnome-shell <= 3.12 switch to 3.12 tag:
`$ sodu git checkout gnome_3.12`
* launch gnome-tweak-tool
* go to Appearance section
* change "Window" and "GTK+" themes to Adwaita-dark

#### 2. Gnome 3.20
Unfurtunately, for gnome 3.20 you have to modify Adwaita theme itself to make it work:
```
$ cd /usr/share/themes/Adwaita
# cp gtk-2.0 gtk-2.0-bkp
# cp -R ../Adwaita-dark/gtk-2.0 ./
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

AUTHORS
=================
originally cloned by Roi M (https://plus.google.com/+RoiMMrNucky/posts/KsybAs8Htgc)
tuned and updated by axxapy
