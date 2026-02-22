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

//SECTION - Definition of the Server class constructor
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
    //SECTION - Initialize Winsock
    // Initialize Winsock to use the Windows Sockets API for network communication. The WSAStartup function is called to initialize the Winsock library, and the WSADATA structure is used to store information about the Windows Sockets implementation.
    WSADATA wsaData;
    // Check if Winsock initialization was successful
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed" << endl;
        return;
    }
    //SECTION - Create a socket
    // Create a socket for listening to incoming connections. The socket is created using the IPv4 address family (AF_INET) and the TCP protocol (SOCK_STREAM). The resulting socket descriptor is stored in listenSocket.
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    // Check if socket creation was successful
    if (listenSocket == INVALID_SOCKET) {
        cerr << "Failed to create socket" << endl;
        WSACleanup();
        return;
    }
    //SECTION - Set up the server address structure
    // Set up the server address structure to bind the socket to the specified port and listen for incoming connections on any available network interface. The server will use IPv4 addressing (AF_INET) and TCP protocol (SOCK_STREAM).
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    //SECTION - Bind the socket to the address and port
    // Bind the socket to the address and port specified in the serverAddress structure. This allows the server to listen for incoming connections on the specified port. The bind function is called to associate the socket with the address and port, and error handling is included to check if the binding was successful.
    // Check if binding was successful
    if (bind(listenSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        cerr << "Bind failed" << endl;
        closesocket(listenSocket);
        WSACleanup();
        return;
    }
    //SECTION - Listen for incoming connections
    // Listen for incoming connections on the bound socket. The listen function is called to mark the socket as a passive socket that will be used to accept incoming connection requests. The SOMAXCONN constant is used to specify the maximum length of the queue of pending connections. Error handling is included to check if the listen operation was successful, and a message is printed to indicate that the server is now listening on the specified port.
    // Check if listening was successful
    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Listen failed" << endl;
        closesocket(listenSocket);
        WSACleanup();
        return;
    }
    // Output a message indicating that the server is listening on the specified port
    cout << "Server listening on port " << port << endl;
    //SECTION - Accept incoming connections
    // Accept incoming connections in an infinite loop. The accept function is called to wait for and accept a client connection. When a client connects, the server receives the client's address information and creates a new socket for communication with the client. Error handling is included to check if accepting the client connection was successful, and a message is printed to indicate that a client has connected.
    while (true) {
        // Accept a client connection
        sockaddr_in clientAddress;
        int clientAddressSize = sizeof(clientAddress);
        SOCKET clientSocket = accept(listenSocket, (sockaddr*)&clientAddress, &clientAddressSize);
        // Check if accepting the client connection was successful
        if (clientSocket == INVALID_SOCKET) {
            cerr << "Accept failed" << endl;
            continue;
        }
        // Output a message indicating that a client has connected
        cout << "Client connected" << endl;
        // Handle the client in a separate thread
        char buffer[1024] = {0};
        int bytesReceived = recv(clientSocket, buffer, 1024, 0);
        // Check if data was received successfully from the client
        if (bytesReceived > 0) {
            string abbreviation(buffer, bytesReceived);
            // Output the received abbreviation for debugging purposes
            cout << "Received abbreviation: " << abbreviation << endl;
            string response;
            // Look up the abbreviation in the stateMap and prepare the response
            if (stateMap.find(abbreviation) != stateMap.end()) {
                response = stateMap[abbreviation];
            }
            // If the abbreviation is not found in the stateMap, prepare an error response
            else {
                response = "Error: Invalid state abbreviation";
            }
            // Send the response back to the client
            send(clientSocket, response.c_str(), response.size(), 0);
        }
        // If receiving data from the client failed, output an error message
        else {
            cerr << "Failed to receive data from client" << endl;
        }
        // Close the client socket after handling the request
        closesocket(clientSocket);
    }
    //SECTION - Close the listening socket and clean up Winsock before exiting the server
    // Close the listening socket and clean up Winsock before exiting the server to free up resources. The closesocket function is called to close the listening socket, and the WSACleanup function is called to clean up the Winsock library before the server exits.
    closesocket(listenSocket);
    // Cleanup Winsock before exiting the server to free up resources
    WSACleanup();
}