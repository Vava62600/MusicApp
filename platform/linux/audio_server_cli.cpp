#include <iostream>
#include <string>
#include "server_manager.h"

void printHelp() {
    std::cout << "Usage: audio_server_cli [command] [options]\n"
              << "Commands:\n"
              << "  start [port]         Start the audio server on the specified port.\n"
              << "  stop                 Stop the audio server.\n"
              << "  connect [host] [port] Connect to a remote audio server.\n"
              << "  disconnect           Disconnect from the remote audio server.\n"
              << "  status               Show the current status of the server.\n"
              << "  clients              List connected clients.\n"
              << "  help                 Show this help message.\n";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printHelp();
        return 1;
    }

    std::string command = argv[1];

    if (command == "start" && argc == 3) {
        int port = std::stoi(argv[2]);
        ServerManager::startAudioServer(port);
    } else if (command == "stop") {
        ServerManager::stopAudioServer();
    } else if (command == "connect" && argc == 4) {
        std::string host = argv[2];
        int port = std::stoi(argv[3]);
        ServerManager::connectToAudioServer(host, port);
    } else if (command == "disconnect") {
        ServerManager::disconnectFromAudioServer();
    } else if (command == "status") {
        std::cout << "Server is " << (ServerManager::isServerRunning() ? "running" : "stopped") << ".\n";
    } else if (command == "clients") {
        auto clients = ServerManager::getConnectedClients();
        if (clients.empty()) {
            std::cout << "No clients connected.\n";
        } else {
            for (const auto &client : clients) {
                std::cout << "Client: " << client << "\n";
            }
        }
    } else {
        printHelp();
    }

    return 0;
}
