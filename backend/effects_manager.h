#ifndef EFFECTS_MANAGER_H
#define EFFECTS_MANAGER_H

#include <string>
#include <vector>

class EffectsManager {
public:
    EffectsManager();
    ~EffectsManager();

    void loadEffectPreset(const std::string &jsonPreset);
    void applyEffect(const std::string &effectName);
    std::vector<std::string> listAvailableEffects();
};

#endif // EFFECTS_MANAGER_H
