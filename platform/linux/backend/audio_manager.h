#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <string>

class AudioManager {
public:
    static void initialize();
    static void applyEffect(const std::string &effectConfig);
    static void removeEffect(const std::string &effectName);
};

#endif // AUDIO_MANAGER_H
