#include <gtk/gtk.h>
#include "effects_controls.h"
#include "effects_manager.h"

// Create an instance of EffectsManager
EffectsManager effectsManager;

// Callback pour appliquer un effet
void on_apply_effect_clicked(GtkWidget *widget, gpointer data) {
    const gchar *effect_name = (const gchar *)data;
    effectsManager.applyEffect(effect_name);
}

// Créer les contrôles des effets audio
GtkWidget* create_effects_controls() {
    GtkWidget *vbox, *label, *button_reverb, *button_echo;

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // Label
    label = gtk_label_new("Effets audio disponibles :");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);

    // Bouton pour appliquer l'effet "Reverb"
    button_reverb = gtk_button_new_with_label("Appliquer Reverb");
    g_signal_connect(button_reverb, "clicked", G_CALLBACK(on_apply_effect_clicked), (gpointer)"Reverb");
    gtk_box_pack_start(GTK_BOX(vbox), button_reverb, FALSE, FALSE, 0);

    // Bouton pour appliquer l'effet "Echo"
    button_echo = gtk_button_new_with_label("Appliquer Echo");
    g_signal_connect(button_echo, "clicked", G_CALLBACK(on_apply_effect_clicked), (gpointer)"Echo");
    gtk_box_pack_start(GTK_BOX(vbox), button_echo, FALSE, FALSE, 0);

    return vbox;
}
