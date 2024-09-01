#ifndef EFFECTS_MANAGER_H
#define EFFECTS_MANAGER_H

#include <string>
#include <vector>

class EffectsManager {
public:
    static std::vector<std::string> listAvailableEffects();
    static void loadEffect(const std::string &effectName);
    static void unloadEffect(const std::string &effectName);
};

#endif // EFFECTS_MANAGER_H
