#ifndef SETTINGS_CONTROLS_H
#define SETTINGS_CONTROLS_H

#include <gtk/gtk.h>

// Crée et retourne les contrôles de paramètres pour l'application
GtkWidget* create_settings_controls();

// Sauvegarde des paramètres utilisateur dans un fichier de configuration
void save_settings(const char *api_choice, gboolean auto_start);

#endif // SETTINGS_CONTROLS_H
