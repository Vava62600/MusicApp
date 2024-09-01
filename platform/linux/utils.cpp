#include <libintl.h>
#include <locale.h>
#include <iostream>

void change_language(const std::string &language) {
    setlocale(LC_ALL, language.c_str());
    bindtextdomain("musicapp", "translations");
    textdomain("musicapp");
    std::cout << "Langue changée à " << language << std::endl;
}