#include "server_manager.h"
#include <windows.h>
#include <iostream>

// Commande pour démarrer PulseAudio en mode serveur
void ServerManager::startPulseAudioServer(const std::string& configFilePath) {
    std::string command = "pulseaudio.exe -n -F " + configFilePath + " --load=\"module-native-protocol-tcp\"";
    system(command.c_str());
    std::cout << "PulseAudio server started with configuration: " << configFilePath << std::endl;
}

// Commande pour connecter le client PulseAudio à un serveur
void ServerManager::connectToPulseAudioServer(const std::string& serverAddress) {
    std::string command = "pacmd.exe load-module module-native-protocol-tcp auth-ip-acl=" + serverAddress;
    system(command.c_str());
    std::cout << "Connected to PulseAudio server at: " << serverAddress << std::endl;
}

// Commande pour arrêter le serveur PulseAudio
void ServerManager::stopPulseAudioServer() {
    system("pulseaudio.exe --kill");
    std::cout << "PulseAudio server stopped." << std::endl;
}

// Basculer vers le mode client
void ServerManager::switchToClientMode() {
    connectToPulseAudioServer("127.0.0.1");  // Exemple d'adresse locale
    std::cout << "Switched to client mode." << std::endl;
}

// Basculer vers le mode serveur
void ServerManager::switchToServerMode() {
    startPulseAudioServer("pulseaudio_config.pa");  // Exemple de fichier de configuration
    std::cout << "Switched to server mode." << std::endl;
}
