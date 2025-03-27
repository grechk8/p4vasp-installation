import os
import sys
from string import strip

def run(cmd):
    os.system("%s > fltk-config.tmp" % cmd)
    return open("fltk-config.tmp").read()

# Forcer l'utilisation du fltk-config du systeme avec OpenGL
print(run("fltk-config --use-gl " + " ".join(sys.argv[1:])))

