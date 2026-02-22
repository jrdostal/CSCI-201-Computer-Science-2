//Server header file a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation. The protocol is binary, and is as follows:
//Server reads the character string and sends back a single character string containing the long name of the state, also in binary form.
//If an invalid abbreviation is sent, the server should respond with an appropriate error response.
//Server closes the connection to the client.
//Server will be a single-threaded server that serializes service to its clients.
//Server will stay in a loop in which it accepts a connection, reads the character data sent through the connection, and sends back the character response through the same connection.
//Server then closes the connection and goes back to wait for another connection.

//!SECTION: The Server class is declared in this header file, which includes necessary libraries and also declares the constructor and the start method. The stateMap is an unordered map that holds the state abbreviations and their corresponding long names. The implementation of the Server class will be in the Server.cpp file, where the server will be set up to listen for incoming connections and handle client requests accordingly.
#ifndef SERVER_H
#define SERVER_H

// Include necessary libraries
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

// Define the Server class
class Server {

// Constructor to initialize the server with a specific port
public:
    // The constructor takes an integer port number as an argument and initializes the server's port member variable.
    Server(int port);
    void start();
private:
    // Member variable to store the port number on which the server will listen for incoming connections
    int port;

    // An unordered map to store state abbreviations as keys and their corresponding long names as values
    unordered_map<string, string> stateMap;
};

#endif // SERVER_H