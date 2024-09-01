#include <gtk/gtk.h>
#include "settings_controls.h"
#include "../backend/server_manager.h"

GtkWidget* create_settings_controls() {
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    GtkWidget *label = gtk_label_new("Settings");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 5);

    // Ajoutez des boutons et des contrôles de paramètres ici

    return vbox;
}
