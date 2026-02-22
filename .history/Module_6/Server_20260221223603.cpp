//Server cpp file a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation. The protocol is binary, and is as follows:
//Server reads the character string and sends back a single character string containing the long name of the state, also in binary form.
//If an invalid abbreviation is sent, the server should respond with an appropriate error response.
//Server closes the connection to the client.
//Server will be a single-threaded server that serializes service to its clients.
//Server will stay in a loop in which it accepts a connection, reads the character data sent through the connection, and sends back the character response through the same connection.
//Server then closes the connection and goes back to wait for another connection.

//!SECTION: The Server class is defined and implemented in this cpp file. The constructor initializes the server with a specific port and populates the stateMap with state abbreviations and their corresponding long names. The start method sets up the server to listen for incoming connections, accepts client requests, processes the state abbreviation sent by the client, and sends back the appropriate response. The server runs in an infinite loop to handle multiple client connections sequentially.

//SECTION - Include necessary libraries
// The following libraries are included for socket programming and handling input/output operations
#include "Server.h"
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

//SECTION - 
// Constructor to initialize the server with a specific port
Server::Server(int port) : port(port) {
    // Initialize the state map with state abbreviations and their corresponding full names
    stateMap["AL"] = "Alabama";
    stateMap["AK"] = "Alaska";
    stateMap["AZ"] = "Arizona";
    stateMap["AR"] = "Arkansas";
    stateMap["CA"] = "California";
    stateMap["CO"] = "Colorado";
    stateMap["CT"] = "Connecticut";
    stateMap["DE"] = "Delaware";
    stateMap["FL"] = "Florida";
    stateMap["GA"] = "Georgia";
    stateMap["HI"] = "Hawaii";
    stateMap["ID"] = "Idaho";
    stateMap["IL"] = "Illinois";
    stateMap["IN"] = "Indiana";
    stateMap["IA"] = "Iowa";
    stateMap["KS"] = "Kansas";
    stateMap["KY"] = "Kentucky";
    stateMap["LA"] = "Louisiana";
    stateMap["ME"] = "Maine";
    stateMap["MD"] = "Maryland";
    stateMap["MA"] = "Massachusetts";
    stateMap["MI"] = "Michigan";
    stateMap["MN"] = "Minnesota";
    stateMap["MS"] = "Mississippi";
    stateMap["MO"] = "Missouri";
    stateMap["MT"] = "Montana";
    stateMap["NE"] = "Nebraska";
    stateMap["NV"] = "Nevada";
    stateMap["NH"] = "New Hampshire";
    stateMap["NJ"] = "New Jersey";
    stateMap["NM"] = "New Mexico";
    stateMap["NY"] = "New York";
    stateMap["NC"] = "North Carolina";
    stateMap["ND"] = "North Dakota";
    stateMap["OH"] = "Ohio";
    stateMap["OK"] = "Oklahoma";
    stateMap["OR"] = "Oregon";
    stateMap["PA"] = "Pennsylvania";
    stateMap["RI"] = "Rhode Island";
    stateMap["SC"] = "South Carolina";
    stateMap["SD"] = "South Dakota";
    stateMap["TN"] = "Tennessee";
    stateMap["TX"] = "Texas";
    stateMap["UT"] = "Utah";
    stateMap["VT"] = "Vermont";
    stateMap["VA"] = "Virginia";
    stateMap["WA"] = "Washington";
    stateMap["WV"] = "West Virginia";
    stateMap["WI"] = "Wisconsin";
    stateMap["WY"] = "Wyoming";
}

//SECTION - The start method sets up the server to listen for incoming connections, accepts client requests, processes the state abbreviation sent by the client, and sends back the appropriate response. The server runs in an infinite loop to handle multiple client connections sequentially.
// The start method initializes Winsock, creates a listening socket, binds it to the specified port, and listens for incoming connections. When a client connects, it receives the state abbreviation, looks it up in the stateMap, and sends back the corresponding full state name or an error message if the abbreviation is invalid. After handling the client request, it closes the client socket and continues to wait for new connections.
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