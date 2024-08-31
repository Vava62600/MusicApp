#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>
#include "main_window.h"
#include "audio_controls.h"
#include "effects_controls.h"
#include "network_controls.h"
#include "settings_controls.h"
#include <fstream>
#include <string>

#define _(STRING) gettext(STRING)

// Charger les paramètres depuis un fichier de configuration
void load_settings(GtkComboBox *combo_box, GtkToggleButton *check_button, GtkComboBox *lang_combo) {
    std::ifstream config("config.txt");
    std::string line;
    if (config.is_open()) {
        while (getline(config, line)) {
            if (line.find("audio_api=") == 0) {
                std::string api = line.substr(10);
                gtk_combo_box_set_active_id(GTK_COMBO_BOX(combo_box), api.c_str());
            } else if (line.find("auto_start=") == 0) {
                std::string auto_start = line.substr(11);
                gtk_toggle_button_set_active(check_button, auto_start == "true");
            } else if (line.find("language=") == 0) {
                std::string language = line.substr(9);
                gtk_combo_box_set_active_id(GTK_COMBO_BOX(lang_combo), language.c_str());
                change_language(language.c_str());
            }
        }
        config.close();
    }
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
