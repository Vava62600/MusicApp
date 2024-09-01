#include "server_manager.h"
#include <iostream>

void ServerManager::startPulseAudioServer(const std::string& configFilePath) {
    std::cout << "Starting PulseAudio server with configuration: " << configFilePath << std::endl;
    // Commande pour démarrer PulseAudio
}

void ServerManager::connectToPulseAudioServer(const std::string& serverAddress) {
    std::cout << "Connecting to PulseAudio server at: " << serverAddress << std::endl;
}

void ServerManager::stopPulseAudioServer() {
    std::cout << "Stopping PulseAudio server." << std::endl;
}

void ServerManager::switchToClientMode() {
    connectToPulseAudioServer("127.0.0.1");
    std::cout << "Switched to client mode." << std::endl;
}

void ServerManager::switchToServerMode() {
    startPulseAudioServer("pulseaudio_config.pa");
    std::cout << "Switched to server mode." << std::endl;
}
