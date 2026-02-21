//Server cpp file a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation. The protocol is binary, and is as follows:
//Server reads the character string and sends back a single character string containing the long name of the state, also in binary form.
//If an invalid abbreviation is sent, the server should respond with an appropriate error response.
//Server closes the connection to the client.
//Server will be a single-threaded server that serializes service to its clients.
//Server will stay in a loop in which it accepts a connection, reads the character data sent through the connection, and sends back the character response through the same connection.
//Server then closes the connection and goes back to wait for another connection.
#include "Server.h"
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

Server::Server(int port) : port(port) {
    // Initialize the state map with some state abbreviations and their corresponding long names
    stateMap["AL"] = "Alabama";
    stateMap["AK"] = "Alaska";
    stateMap["AZ"] = "Arizona";
    stateMap["AR"] = "Arkansas";
    stateMap["CA"] = "California";
    // Add more states as needed
}

void Server::start() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed" << endl;
        return;
    }
    // Create a socket
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket == INVALID_SOCKET) {
        cerr << "Failed to create socket" << endl;
        WSACleanup();
        return;
    }
    // Set up the server address structure
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    // Bind the socket to the address and port
    if (bind(listenSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        cerr << "Bind failed" << endl;
        closesocket(listenSocket);
        WSACleanup();
        return;
    }
    // Listen for incoming connections
    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Listen failed" << endl;
        closesocket(listenSocket);
        WSACleanup();
        return;
    }
    cout << "Server listening on port " << port << endl;
    // Accept incoming connections
    while (true) {
        sockaddr_in clientAddress;
        int clientAddressSize = sizeof(clientAddress);
        SOCKET clientSocket = accept(listenSocket, (sockaddr*)&clientAddress, &clientAddressSize);
        if (clientSocket == INVALID_SOCKET) {
            cerr << "Accept failed" << endl;
            continue;
        }
        cout << "Client connected" << endl;
        // Handle the client in a separate thread
        char buffer[1024] = {0};
        int bytesReceived = recv(clientSocket, buffer, 1024, 0);
        if (bytesReceived > 0) {
            string abbreviation(buffer, bytesReceived);
            cout << "Received abbreviation: " << abbreviation << endl;
            string response;
            if (stateMap.find(abbreviation) != stateMap.end()) {
                response = stateMap[abbreviation];
            } else {
                response = "Error: Invalid state abbreviation";
            }
            send(clientSocket, response.c_str(), response.size(), 0);
        } else {
            cerr << "Failed to receive data from client" << endl;
        }
        closesocket(clientSocket);
    }
    closesocket(listenSocket);
    WSACleanup();
}