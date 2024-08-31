#include <gtk/gtk.h>
#include <fstream>
#include <iostream>
#include "settings_controls.h"

// Fichier de configuration pour enregistrer les préférences utilisateur
const char *CONFIG_FILE = "config.txt";

// Sauvegarde des paramètres dans un fichier de configuration
void save_settings(const char *api_choice, gboolean auto_start) {
    std::ofstream config(CONFIG_FILE);
    if (config.is_open()) {
        config << "audio_api=" << api_choice << std::endl;
        config << "auto_start=" << (auto_start ? "true" : "false") << std::endl;
        config.close();
    } else {
        std::cerr << "Impossible d'ouvrir le fichier de configuration." << std::endl;
    }
}

// Callback pour le changement de l'API audio
void on_audio_api_changed(GtkComboBox *widget, gpointer data) {
    const gchar *api_choice = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget));
    if (api_choice) {
        // Sauvegarder le choix de l'API audio
        save_settings(api_choice, gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data)));
        g_free((gchar *)api_choice);
    }
}

// Callback pour le démarrage automatique
void on_auto_start_toggled(GtkToggleButton *toggle_button, gpointer data) {
    gboolean auto_start = gtk_toggle_button_get_active(toggle_button);
    // Sauvegarder le paramètre de démarrage automatique
    save_settings((const char *)data, auto_start);
}

// Créer les contrôles des paramètres
GtkWidget* create_settings_controls() {
    GtkWidget *vbox, *label, *combo_box, *check_button;

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // Label pour API audio
    label = gtk_label_new("Choisir l'API Audio :");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);

    // ComboBox pour choisir l'API audio
    combo_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "PulseAudio");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "PipeWire");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "ALSA");

    g_signal_connect(combo_box, "changed", G_CALLBACK(on_audio_api_changed), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), combo_box, FALSE, FALSE, 0);

    // Checkbox pour le démarrage automatique
    check_button = gtk_check_button_new_with_label("Démarrer avec le système");
    g_signal_connect(check_button, "toggled", G_CALLBACK(on_auto_start_toggled), (gpointer)"PulseAudio");
    gtk_box_pack_start(GTK_BOX(vbox), check_button, FALSE, FALSE, 0);

    return vbox;
}
// Charger les paramètres depuis un fichier de configuration
void load_settings(GtkComboBox *combo_box, GtkToggleButton *check_button) {
    std::ifstream config(CONFIG_FILE);
    std::string line;
    if (config.is_open()) {
        while (getline(config, line)) {
            if (line.find("audio_api=") == 0) {
                std::string api = line.substr(10);
                gtk_combo_box_set_active_id(GTK_COMBO_BOX(combo_box), api.c_str());
            } else if (line.find("auto_start=") == 0) {
                std::string auto_start = line.substr(11);
                gtk_toggle_button_set_active(check_button, auto_start == "true");
            }
        }
        config.close();
    }
}

// Modifier create_settings_controls pour charger les paramètres
GtkWidget* create_settings_controls() {
    GtkWidget *vbox, *label, *combo_box, *check_button;

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    label = gtk_label_new("Choisir l'API Audio :");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);

    combo_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "PulseAudio");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "PipeWire");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "ALSA");

    check_button = gtk_check_button_new_with_label("Démarrer avec le système");

    load_settings(GTK_COMBO_BOX(combo_box), GTK_TOGGLE_BUTTON(check_button));

    g_signal_connect(combo_box, "changed", G_CALLBACK(on_audio_api_changed), check_button);
    gtk_box_pack_start(GTK_BOX(vbox), combo_box, FALSE, FALSE, 0);

    g_signal_connect(check_button, "toggled", G_CALLBACK(on_auto_start_toggled), (gpointer)"PulseAudio");
    gtk_box_pack_start(GTK_BOX(vbox), check_button, FALSE, FALSE, 0);

    return vbox;
}

