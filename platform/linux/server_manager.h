#ifndef SERVER_MANAGER_H
#define SERVER_MANAGER_H

#include <string>
#include <vector>

class ServerManager {
public:
    static bool startAudioServer(int port);
    static void stopAudioServer();
    static bool connectToAudioServer(const std::string& host, int port);
    static void disconnectFromAudioServer();
    static void addServer(const std::string& serverName);  // Assurez-vous que cette ligne est ici
    static bool isServerRunning();
    static std::vector<std::string> getConnectedClients();

private:
    static std::vector<std::string> servers;  // Liste des serveurs
};

#endif // SERVER_MANAGER_H
