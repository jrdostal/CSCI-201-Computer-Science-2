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
#include <unistd.h>
#include <cstring>

Client::Client(const std::string& serverIp, int port) : serverIp(serverIp), port(port) {}

void Client::run() {
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return;
    }
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }
    // Connect to the server
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    if (inet_pton(AF_INET, serverIp.c_str(), &serverAddress.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return;
    }
    if (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Failed to connect to server" << std::endl;
        return;
    }
    // Ask user for state abbreviation
    std::string abbreviation;
    std::cout << "Enter a two-letter state abbreviation: ";
    std::cin >> abbreviation;
    // Send the abbreviation to the server
    write(sock, abbreviation.c_str(), abbreviation.length());
    // Read the response from the server
    char buffer[1024] = {0};
    int bytesRead = read(sock, buffer, 1024);
    if (bytesRead > 0) {
        std::cout << "Server response: " << buffer << std::endl;
    } else {
        std::cerr << "Failed to read from server" << std::endl;
    }
    close(sock);
}