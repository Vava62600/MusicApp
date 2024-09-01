#include "server_manager.h"
#include <iostream>
#include <vector>

std::vector<std::string> ServerManager::servers;  // Initialiser la liste des serveurs

void ServerManager::addServer(const std::string& serverName) {  // Implémentation de la méthode
    servers.push_back(serverName);
    std::cout << "Serveur ajouté : " << serverName << std::endl;
}

// Déclarations internes (vous pouvez utiliser des sockets ou d'autres bibliothèques réseau)
static bool serverRunning = false;
static std::vector<std::string> connectedClients;

bool ServerManager::startAudioServer(int port) {
    if (serverRunning) {
        std::cerr << "Le serveur est déjà en cours d'exécution sur le port " << port << "." << std::endl;
        return false;
    }
    // Logique pour démarrer le serveur
    std::cout << "Démarrage du serveur audio sur le port " << port << "..." << std::endl;
    serverRunning = true; // Simuler le démarrage
    return true;
}

void ServerManager::stopAudioServer() {
    if (!serverRunning) {
        std::cerr << "Le serveur n'est pas en cours d'exécution." << std::endl;
        return;
    }
    // Logique pour arrêter le serveur
    std::cout << "Arrêt du serveur audio..." << std::endl;
    serverRunning = false; // Simuler l'arrêt
}

bool ServerManager::connectToAudioServer(const std::string& host, int port) {
    if (serverRunning) {
        std::cerr << "Impossible de se connecter à un serveur distant en tant que serveur." << std::endl;
        return false;
    }
    // Logique pour se connecter à un serveur distant
    std::cout << "Connexion au serveur audio sur " << host << ":" << port << "..." << std::endl;
    connectedClients.push_back(host); // Simuler la connexion d'un client
    return true;
}

void ServerManager::disconnectFromAudioServer() {
    if (connectedClients.empty()) {
        std::cerr << "Aucun client connecté." << std::endl;
        return;
    }
    // Logique pour se déconnecter du serveur distant
    std::cout << "Déconnexion du serveur audio..." << std::endl;
    connectedClients.clear(); // Simuler la déconnexion
}

bool ServerManager::isServerRunning() {
    return serverRunning;
}

std::vector<std::string> ServerManager::getConnectedClients() {
    return connectedClients;
}
