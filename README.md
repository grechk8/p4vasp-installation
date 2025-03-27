p4vasp-installation
==========================

Copyright notes:
The p4vasp is distributed under the General Public License version 2 (GPL2).

For more information and support visit www.p4vasp.at.

Binary distributions
==========================

Binary distribution contains a single executable file.
Place this file at a convenient location (e.g. Desktop)
and add it to the system PATH.
P4vasp is a portable application - it can be started from a usb drive.

Requirements
==========================

Ubuntu 20.04/22.04 (or WSL with Ubuntu)

Python 2.7

GTK2 (libgtk2.0, libglade2)

FLTK 1.3 + OpenGL

Source-code distributions
==========================

Compilation Quickstart
--------------------------

clone this repo
```
   git clone https://github.com/grechk8/p4vasp-install.git
```
Change directory:               
```
   cd p4vasp-install
```

Run the custom installation script

```
   chmod +x install_p4vasp_env.sh
   ./install.sh
```

run
```
   export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0
```


Starting:
--------------------------

Start with: `p4v`

```
   p4v
```

Look at the documentation in the `doc/intro/intro.html`
(or `/usr/lib/p4vasp/doc/intro.html`, when installed),
if you need some clues how to deal with the p4v GUI.

Some people prefer command-line tools and automatic scripts
to a graphical interface. For those, there are some simple
scripts in the utils directory (`/usr/lib/p4vasp/utils`).
They are also a good example for the p4vasp-API.


P4vasp package embeds the odpdom library, that is available also as a [separate
project](http://sourceforge.net/projects/odpdom) and a slightly modified version
of the [piddle library](piddle.sourceforge.net).
Both odpdom and piddle are available under the LGPL License (see
odpdom/COPYING).

This package as well may contain other packages (in ext directory) under various open-source licenses:
[fltk](www.fltk.org), [sqlite](www.sqlite.org) and [pysqlite](code.google.com/p/pysqlite).
These packages are provided for convenience only to make the installation easier.
==========================


Authors

Grech Kitio

Initial project: p4vasp + WSL/Ubuntu custom patches
==========================
