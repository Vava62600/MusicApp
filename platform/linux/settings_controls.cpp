#include <gtk/gtk.h>
#include <fstream>
#include <iostream>
#include "settings_controls.h"
#include "audio_manager.h"
#include "utils.h"  // Inclure le fichier d'en-tête où change_language est déclaré

// Fonction pour créer les contrôles des paramètres
GtkWidget* create_settings_controls() {
    GtkWidget *vbox, *label, *combo_box, *check_button, *lang_label, *lang_combo;

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // Label pour l'API audio
    label = gtk_label_new("Choose Audio API:");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);

    // ComboBox pour choisir l'API audio
    combo_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "PulseAudio");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "PipeWire");

    gtk_box_pack_start(GTK_BOX(vbox), combo_box, FALSE, FALSE, 0);

    // Checkbox pour le démarrage automatique
    check_button = gtk_check_button_new_with_label("Start with the system");
    gtk_box_pack_start(GTK_BOX(vbox), check_button, FALSE, FALSE, 0);

    // Label pour changer de langue
    lang_label = gtk_label_new("Choose Language:");
    gtk_box_pack_start(GTK_BOX(vbox), lang_label, FALSE, FALSE, 0);

    // ComboBox pour sélectionner la langue
    lang_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(lang_combo), "fr_FR.UTF-8");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(lang_combo), "nl_NL.UTF-8");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(lang_combo), "en_US.UTF-8");

    gtk_box_pack_start(GTK_BOX(vbox), lang_combo, FALSE, FALSE, 0);

    return vbox;
}
