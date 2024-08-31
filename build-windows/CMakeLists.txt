cmake_minimum_required(VERSION 3.10)
project(MusicAppWindows)

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)

set(CMAKE_CXX_STANDARD 17)

# Définir le répertoire d'inclusion et les bibliothèques
include_directories(/usr/x86_64-w64-mingw32/include)
link_directories(/usr/x86_64-w64-mingw32/lib)

# Ajouter le wrapper PulseWrapper pour Windows
add_library(PulseWrapper pulse_wrapper.cpp)

# Application principale
add_executable(MusicApp main.cpp)
target_link_libraries(MusicApp PulseWrapper)
