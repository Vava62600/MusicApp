#include "effects_manager.h"
#include <iostream>
#include <vector>

std::vector<std::string> EffectsManager::listAvailableEffects() {
    return {"Reverb", "Echo", "Bass Boost"};
}

void EffectsManager::loadEffect(const std::string &effectName) {
    std::cout << "Loading effect: " << effectName << std::endl;
}

void EffectsManager::unloadEffect(const std::string &effectName) {
    std::cout << "Unloading effect: " << effectName << std::endl;
}
