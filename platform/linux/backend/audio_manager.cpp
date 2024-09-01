#include "audio_manager.h"
#include <iostream>

void AudioManager::initialize() {
    std::cout << "Initializing Audio Manager with PulseAudio..." << std::endl;
}

void AudioManager::applyEffect(const std::string &effectConfig) {
    std::cout << "Applying effect from config: " << effectConfig << std::endl;
    // Utiliser json-c pour charger et appliquer les effets
}

void AudioManager::removeEffect(const std::string &effectName) {
    std::cout << "Removing effect: " << effectName << std::endl;
}
