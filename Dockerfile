FROM ubuntu:18.04

ENV DEBIAN_FRONTEND=noninteractive

# Installer les dépendances
RUN apt-get update && apt-get install -y \
    python \
    python-gtk2 \
    python-numpy \
    python-matplotlib \
    python-opengl \
    git \
    x11-apps \
    && apt-get clean

# Copier ton projet dans l'image
COPY . /app
WORKDIR /app

# Exécute p4vasp au démarrage
CMD ["python", "p4v.py"]

