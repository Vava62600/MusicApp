#ifndef SERVER_MANAGER_H
#define SERVER_MANAGER_H

#include <string>

class ServerManager {
public:
    static void startPulseAudioServer(const std::string& configFilePath);
    static void connectToPulseAudioServer(const std::string& serverAddress);
    static void stopPulseAudioServer();
    static void switchToClientMode();
    static void switchToServerMode();
};

#endif // SERVER_MANAGER_H
