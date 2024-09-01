#include <gtk/gtk.h>
#include "main_window.h"
#include "audio_controls.h"
#include "effects_controls.h"
#include "network_controls.h"
#include "settings_controls.h"

// Fonction principale
int main(int argc, char *argv[]) {
    // Initialisez GTK
    gtk_init(&argc, &argv);

    // Créez la fenêtre principale
    GtkWidget *mainWindow = create_main_window();
    gtk_widget_show_all(mainWindow);

    // Entrez dans la boucle principale GTK
    gtk_main();

    return 0;
}

GtkWidget* create_main_window() {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "MusicApp");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *notebook = gtk_notebook_new();
    gtk_container_add(GTK_CONTAINER(window), notebook);

    // Créer et ajouter des pages de contrôles
    GtkWidget *audio_controls = create_audio_controls();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), audio_controls, gtk_label_new("Audio"));

    // Assurez-vous que les autres contrôles sont créés correctement
    GtkWidget *effects_controls = create_effects_controls();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), effects_controls, gtk_label_new("Effects"));

    GtkWidget *network_controls = create_network_controls();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), network_controls, gtk_label_new("Network"));

    GtkWidget *settings_controls = create_settings_controls();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), settings_controls, gtk_label_new("Settings"));

    return window;
}
