#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtk-4.0/gtk/gtk.h>

// Crée et retourne la fenêtre principale de l'application
GtkWidget* create_main_window();

// Gestionnaire de signal pour le bouton "À propos"
// Affiche une boîte de dialogue avec des informations sur l'application
void on_about_button_clicked(GtkWidget *widget, gpointer data);

#endif // MAIN_WINDOW_H
