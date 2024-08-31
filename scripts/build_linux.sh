#!/bin/bash

# Mettre à jour les paquets
sudo apt update

# Installer les dépendances de build
sudo apt install -y build-essential cmake gettext libgtk-3-dev libglib2.0-dev libpulse-dev libadwaita-1-dev

# Créer le répertoire de build
mkdir -p build
cd build

# Configurer le projet avec CMake
cmake ..

# Compiler le projet
make

# Installer les fichiers de localisation
cd ..
mkdir -p po
cp translations/*.po po/
cd po
for file in *.po; do
    msgfmt "$file" -o "${file%.po}.mo"
    sudo cp "${file%.po}.mo" /usr/share/locale/${file%.po}/LC_MESSAGES/musicapp.mo
done
cd ..

# Créer un paquet Debian
mkdir -p MusicApp/DEBIAN
cat <<EOF > MusicApp/DEBIAN/control
Package: musicapp
Version: 1.0
Section: base
Priority: optional
Architecture: amd64
Depends: libgtk-3-0, libglib2.0-0, libpulse0, libadwaita-1-0
Maintainer: Vava <vava62600@outlook.com>
Description: MusicApp est une application de gestion audio multiplateforme.
EOF

# Copier les fichiers binaires et autres ressources dans le dossier du paquet
mkdir -p MusicApp/usr/local/bin
cp build/MusicApp MusicApp/usr/local/bin/
dpkg-deb --build MusicApp

echo "Le paquet Debian est créé : MusicApp.deb"
