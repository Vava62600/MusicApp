#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <string>

#ifdef _WIN32
#include "platform/windows/pulse_wrapper.h"
#else
#include "platform/linux/pulse_pipe_wrapper.h"
#endif

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    void initialize();
    void setOutputDevice(const std::string &deviceName);
    void createVirtualOutput(const std::string &virtualOutputName);
    std::string getCurrentOutputDevice();
    void startSystemAudio();
    void stopSystemAudio();
};

#endif // AUDIO_MANAGER_H
