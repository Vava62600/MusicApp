#ifndef PULSE_PIPE_WRAPPER_H
#define PULSE_PIPE_WRAPPER_H

#include <string>
#include <vector>

class PulsePipeWrapper {
public:
    static void initialize();
    static void initializePulseAudio();
    static void initializePipeWire();
    static void setOutputDevice(const std::string& deviceName);
    static void createVirtualOutput(const std::string& virtualOutputName);
    static std::string getCurrentOutputDevice();
    static void applyEffect(const std::string& effectName);
};

#endif // PULSE_PIPE_WRAPPER_H
