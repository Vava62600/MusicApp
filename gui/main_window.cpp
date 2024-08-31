#include <libintl.h>
#include <locale.h>
#include <gtk/gtk.h>
#include "main_window.h"
#include "audio_controls.h"
#include "effects_controls.h"
#include "network_controls.h"
#include "settings_controls.h"

#define _(STRING) gettext(STRING)

GtkWidget* create_main_window() {
    GtkWidget *window;
    GtkWidget *notebook;
    GtkWidget *audio_controls, *effects_controls, *network_controls, *settings_controls;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "MusicApp");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    notebook = gtk_notebook_new();
    gtk_container_add(GTK_CONTAINER(window), notebook);

    // Ajouter les différents onglets
    audio_controls = create_audio_controls();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), audio_controls, gtk_label_new("Audio"));

    effects_controls = create_effects_controls();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), effects_controls, gtk_label_new("Effets"));

    network_controls = create_network_controls();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), network_controls, gtk_label_new("Réseau"));

    settings_controls = create_settings_controls();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), settings_controls, gtk_label_new("Paramètres"));

    return window;
}
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *mainWindow = create_main_window();
    gtk_widget_show_all(mainWindow);

    gtk_main();
    return 0;
}
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");
    bindtextdomain("musicapp", "translations");
    textdomain("musicapp");

    gtk_init(&argc, &argv);

    GtkWidget *mainWindow = create_main_window();
    gtk_widget_show_all(mainWindow);

    gtk_main();
    return 0;
}
