//Server cpp file a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation. The protocol is binary, and is as follows:
//Server reads the character string and sends back a single character string containing the long name of the state, also in binary form.
//If an invalid abbreviation is sent, the server should respond with an appropriate error response.
//Server closes the connection to the client.
//Server will be a single-threaded server that serializes service to its clients.
//Server will stay in a loop in which it accepts a connection, reads the character data sent through the connection, and sends back the character response through the same connection.
//Server then closes the connection and goes back to wait for another connection.
#include "Server.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

Server::Server(int port) : port(port) {
    // Initialize the state map with some state abbreviations and their long names
    stateMap["AL"] = "Alabama";
    stateMap["AK"] = "Alaska";
    stateMap["AZ"] = "Arizona";
    stateMap["AR"] = "Arkansas";
    stateMap["CA"] = "California";
    // Add more states as needed
}

void Server::start() {
    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }
    // Bind the socket to the specified port
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == -1) {
        std::cerr << "Failed to bind socket" << std::endl;
        return;
    }
    // Listen for incoming connections
    if (listen(server_fd, 3) == -1) {
        std::cerr << "Failed to listen on socket" << std::endl;
        return;
    }
    std::cout << "Server listening on port " << port << std::endl;
    // Accept incoming connections and handle them
    while (true) {
        int client_fd = accept(server_fd, nullptr, nullptr);
        if (client_fd == -1) {
            std::cerr << "Failed to accept connection" << std::endl;
            continue;
        }
        // Handle the client connection in a separate thread
        char buffer[1024] = {0};
        read(client_fd, buffer, 1024);
        std::string abbreviation(buffer);
        std::string response;
        if (stateMap.find(abbreviation) != stateMap.end()) {
            response = stateMap[abbreviation];
        } else {
            response = "Error: Invalid state abbreviation";
        }
        write(client_fd, response.c_str(), response.length());
        close(client_fd);
    }
}

int main() {
    Server server(8080);
    server.start();
    return 0;
}
#endif // SERVER_H