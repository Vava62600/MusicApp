#include <gtk/gtk.h>
#include "effects_controls.h"
#include "../backend/effects_manager.h"

GtkWidget* create_effects_controls() {
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    GtkWidget *label = gtk_label_new("Audio Effects");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 5);

    // Ajouter les boutons et les contrôles pour gérer les effets

    return vbox;
}
