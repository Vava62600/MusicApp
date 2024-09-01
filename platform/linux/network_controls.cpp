#include <gtk/gtk.h>
#include "network_controls.h"
#include "server_manager.h"

// Callback pour ajouter un serveur
void on_add_server_clicked(GtkWidget *widget, gpointer data) {
    // Logique pour ajouter un serveur (à implémenter dans ServerManager)
    ServerManager::addServer("Nouvelle Connexion Serveur");
    g_print("Serveur ajouté.\n");
}

// Créer les contrôles de gestion du réseau
GtkWidget* create_network_controls() {
    GtkWidget *vbox, *label, *button_add_server;

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // Label
    label = gtk_label_new("Gestion des serveurs :");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);

    // Bouton pour ajouter un serveur
    button_add_server = gtk_button_new_with_label("Ajouter un serveur");
    g_signal_connect(button_add_server, "clicked", G_CALLBACK(on_add_server_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), button_add_server, FALSE, FALSE, 0);

    return vbox;
}
