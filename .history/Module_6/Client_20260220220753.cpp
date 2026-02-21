//CLient cpp file a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation. The protocol is binary, and is as follows:
//Client connects and sends the two-letter state abbreviation in binary form.
//Client should ask the user for a state abbreviation, read the user input, open a connection to the server, and send the data.
//Client should then read the reply and print it (the long name of the state) to the screen.
#include "Client.h"
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

Client::Client(const std::string& serverIp, int port) : serverIp(serverIp), port(port) {}

void Client::run() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed" << endl;
        return;
    }
    // Create a socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cerr << "Failed to create socket" << endl;
        WSACleanup();
        return;
    }
    // Set up the server address structure
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    inet_pton(AF_INET, serverIp.c_str(), &serverAddress.sin_addr);
    // Connect to the server
    if (connect(sock, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        cerr << "Failed to connect to server" << endl;
        closesocket(sock);
        WSACleanup();
        return;
    }
    // Get user input for state abbreviation
    string abbreviation;
    cout << "Enter a state abbreviation: ";
    cin >> abbreviation;
    // Send the abbreviation to the server
    send(sock, abbreviation.c_str(), abbreviation.size(), 0);
    // Receive the response from the server
    char buffer[1024] = {0};
    int bytesReceived = recv(sock, buffer, 1024, 0);
    if (bytesReceived > 0) {
        cout << "State name: " << string(buffer, bytesReceived) << endl;
    } else {
        cout << "Failed to receive response from server" << endl;
    }
    // Close the socket and cleanup
    closesocket(sock);
    WSACleanup();
}