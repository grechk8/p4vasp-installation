#!/bin/bash
set -e

# Installer dépendances système
sudo apt update
sudo apt install -y python2 python2-dev build-essential curl \
                   libfltk1.3-dev libfltk-gl1.3 libgtk2.0-dev freeglut3-dev

# Installer python-glade2 depuis le .deb archivé
sudo apt install -y ./python-glade2_2.24.0-5.1ubuntu2_amd64.deb

# Installer pip2
curl https://bootstrap.pypa.io/pip/2.7/get-pip.py -o get-pip.py
sudo python2 get-pip.py

# Installer PyOpenGL, numpy
pip2 install pyopengl numpy

# Compiler p4vasp
cd /chemin/vers/p4vasp
make clean || true
rm -f python-packages/_cp4vasp.so python-packages/cp4vasp.py || true
make local # make config
make install # sudo make install


make bashrc

