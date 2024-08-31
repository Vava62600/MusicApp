#include <gtk/gtk.h>
#include "audio_controls.h"
#include "../backend/audio_manager.h"

// Callback pour changer de périphérique de sortie
void on_output_device_changed(GtkComboBox *widget, gpointer data) {
    const gchar *device_name = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget));
    if (device_name) {
        AudioManager::setOutputDevice(device_name);
        g_free((gchar *)device_name);
    }
}

// Créer les contrôles audio
GtkWidget* create_audio_controls() {
    GtkWidget *vbox, *label, *combo_box;
    
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    
    // Label
    label = gtk_label_new("Sélectionner le périphérique de sortie audio :");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);

    // ComboBox pour sélectionner le périphérique de sortie
    combo_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "Sortie par défaut");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "Casque");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "Haut-parleurs externes");
    g_signal_connect(combo_box, "changed", G_CALLBACK(on_output_device_changed), NULL);
    
    gtk_box_pack_start(GTK_BOX(vbox), combo_box, FALSE, FALSE, 0);
    
    return vbox;
}
