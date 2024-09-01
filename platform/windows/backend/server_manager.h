#ifndef SERVER_MANAGER_H
#define SERVER_MANAGER_H

#include <string>

class ServerManager {
public:
    // Mode Serveur PulseAudio
    static void startPulseAudioServer(const std::string& configFilePath);

    // Mode Client PulseAudio
    static void connectToPulseAudioServer(const std::string& serverAddress);

    // Arrêter le serveur PulseAudio
    static void stopPulseAudioServer();

    // Basculer vers le mode client ou serveur
    static void switchToClientMode();
    static void switchToServerMode();
};

#endif // SERVER_MANAGER_H
