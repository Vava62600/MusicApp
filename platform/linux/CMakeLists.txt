cmake_minimum_required(VERSION 3.10)
project(MusicAppLinux)

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
    gui/main_window.cpp
    gui/audio_controls.cpp
    gui/effects_controls.cpp
    gui/network_controls.cpp
    backend/audio_manager.cpp
    backend/effects_manager.cpp
    platform/linux/pulse_pipe_wrapper.cpp
)

# Exécutable principal
add_executable(MusicApp ${SOURCES})
target_link_libraries(MusicApp ${GTK3_LIBRARIES} ${PULSEAUDIO_LIBRARIES} ${LIBADWAITA_LIBRARIES})
