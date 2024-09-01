cmake_minimum_required(VERSION 3.10)
project(MusicApp)

set(CMAKE_CXX_STANDARD 17)

# Trouver les packages nécessaires
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(PULSEAUDIO REQUIRED libpulse)
pkg_check_modules(LIBADWAITA REQUIRED libadwaita-1)

include_directories(
    ${GTK3_INCLUDE_DIRS}
    ${PULSEAUDIO_INCLUDE_DIRS}
    ${LIBADWAITA_INCLUDE_DIRS}
    ../../gui
    ../../backend
    ../../platform/linux  # Assurez-vous que ce répertoire est ajouté ici
)

link_directories(
    ${GTK3_LIBRARY_DIRS}
    ${PULSEAUDIO_LIBRARY_DIRS}
    ${LIBADWAITA_LIBRARY_DIRS}
)

# Ajouter les définitions
add_definitions(${GTK3_CFLAGS_OTHER})

# Fichiers sources
set(SOURCES
    main_window.cpp
    audio_controls.cpp
    effects_controls.cpp
    network_controls.cpp
    settings_controls.cpp  # Ce fichier doit être présent
    audio_manager.cpp
    effects_manager.cpp
    server_manager.cpp
    pulse_pipe_wrapper.cpp
    utils.cpp
)

# Exécutable principal
add_executable(MusicApp ${SOURCES})
target_link_libraries(MusicApp ${GTK3_LIBRARIES} ${PULSEAUDIO_LIBRARIES} ${LIBADWAITA_LIBRARIES})
