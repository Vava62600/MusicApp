#!/bin/bash

# Détection de la version de Debian/Ubuntu
VERSION=$(lsb_release -sc)

echo "Installation des dépendances pour MusicApp sur $VERSION..."

# Mettre à jour les paquets
sudo apt update

# Installer les dépendances de base
sudo apt install -y build-essential cmake gettext libgtk-3-dev libglib2.0-dev libpulse-dev

# Gestion des dépendances spécifiques selon la version
case $VERSION in
    bullseye|bookworm|sid) # Debian 11 à 13
        sudo apt install -y libadwaita-1-dev
        ;;
    focal|jammy|kinetic) # Ubuntu 20.04 à 22.04+
        sudo apt install -y libadwaita-1-dev
        ;;
    *)
        echo "Version non supportée directement. Veuillez vérifier les dépendances manuellement."
        ;;
esac

echo "Dépendances installées."
