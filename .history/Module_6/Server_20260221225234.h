//Server header file a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation. The protocol is binary, and is as follows:
//Server reads the character string and sends back a single character string containing the long name of the state, also in binary form.
//If an invalid abbreviation is sent, the server should respond with an appropriate error response.
//Server closes the connection to the client.
//Server will be a single-threaded server that serializes service to its clients.
//Server will stay in a loop in which it accepts a connection, reads the character data sent through the connection, and sends back the character response through the same connection.
//Server then closes the connection and goes back to wait for another connection.

//!SECTION: The Server class is declared in this header file, which includes necessary libraries and also declares the constructor and the start method. The stateMap is an unordered map that holds the state abbreviations and their corresponding long names. The implementation of the Server class will be in the Server.cpp file, where the server will be set up to listen for incoming connections and handle client requests accordingly.

//SECTION - Define include guard to prevent multiple inclusions of this header file
// The following lines define an include guard to ensure that the contents of this header file are not included multiple times in a single compilation unit, which can cause errors.
#ifndef SERVER_H
#define SERVER_H

//SECTION - Include necessary libraries
// The following libraries are included for socket programming and handling input/output operations
#include <string>
#include <unordered_map>
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//SECTION - Declaration of the Server class
// The Server class encapsulates the functionality of the server, including initializing the server, handling client connections, and processing state abbreviations to return the corresponding long names.
class Server {

//SECTION - Public members of the Server class
// The constructor takes an integer port number as an argument and initializes the server's port member variable. The start method is responsible for setting up the server to listen for incoming connections and handling client requests.
public:
    // SECTION - Constructor for the Server class
    // The constructor takes an integer port number as an argument and initializes the server's port member variable. The port member variable will be used to specify the port on which the server will listen for incoming connections from clients. The constructor also initializes the stateMap with state abbreviations and their corresponding long names, which will be used to look up the full state name based on the abbreviation received from the client.
    Server(int port);
    //SECTION - Start method for the Server class
    // The start method is responsible for setting up the server to listen for incoming connections and handling client requests. It initializes Winsock, creates a listening socket, binds it to the specified port, and listens for incoming connections. When a client connects, it receives the state abbreviation, looks it up in the stateMap, and sends back the corresponding full state name or an error message if the abbreviation is invalid. After handling the client request, it closes the client socket and continues to wait for new connections.
    void start();

//SECTION - Private members of the Server class
// The port member variable stores the port number on which the server will listen for incoming connections. The stateMap is an unordered map that holds state abbreviations as keys and their corresponding long names as values, which will be used to look up the full state name based on the abbreviation received from the client.
private:

    // Member variable to store the port number on which the server will listen for incoming connections
    int port;
    // An unordered map to store state abbreviations as keys and their corresponding long names as values
    unordered_map<string, string> stateMap;
};

//SECTION - End of the Server class declaration
#endif // SERVER_H