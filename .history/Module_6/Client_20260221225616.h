//CLient header file of a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation. The protocol is binary, and is as follows:
//Client connects and sends the two-letter state abbreviation in binary form.
//Client should ask the user for a state abbreviation, read the user input, open a connection to the server, and send the data.
//Client should then read the reply and print it (the long name of the state) to the screen.

//!SECTION: The Client class is declared in this header file, which includes necessary libraries and also declares the constructor and the run method. The serverIp member variable stores the IP address of the server, and the port member variable stores the port number on which the server is listening for incoming connections. The implementation of the Client class will be in the Client.cpp file, where the client will connect to the server, send state abbreviations, and receive responses accordingly.

//SECTION - Define include guard to prevent multiple inclusions of this header file
// The following lines define an include guard to ensure that the contents of this header file are not included multiple times in a single compilation unit, which can cause errors.
#ifndef CLIENT_H
#define CLIENT_H

//SECTION - Include necessary libraries
// The following libraries are included for socket programming and handling input/output operations
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

//SECTION - Declaration of the Client class
// The Client class encapsulates the functionality of the client, including connecting to the server, sending state abbreviations, and receiving responses from the server.
class Client {

//SECTION - Public members of the Client class
public:

    //SECTION - Constructor for the Client class
    // The constructor takes the server's IP address and port number as arguments and initializes the corresponding member variables. The serverIp member variable stores the IP address of the server, and the port member variable stores the port number on which the server is listening for incoming connections.
    Client(const string& serverIp, int port);
    //SECTION - Destructor for the Client class
    // The destructor is defined to perform any necessary cleanup when a Client object is destroyed. In this case, it is left empty as there are no specific resources that need to be released when the Client object is destroyed. However, it is good practice to define a destructor in case any future modifications to the Client class require cleanup of resources.
    ~Client() {}

    //SECTION - Run method for the Client class
    // The run method is responsible for connecting to the server, sending state abbreviations, and receiving responses from the server. It initializes Winsock, creates a socket, connects to the server, sends the user input (state abbreviation), receives the response from the server, and prints it to the screen. The method also includes error handling for socket operations and allows the user to exit the program gracefully.
    void run();

//SECTION - Private members of the Client class
private:

    //SECTION - Member variables for the Client class
    // The serverIp member variable stores the IP address of the server, and the port member variable stores the port number on which the server is listening for incoming connections. These member variables are initialized in the constructor and used in the run method to establish a connection to the server and communicate with it.
    string serverIp;
    int port;
};

//SECTION - End of the Client class declaration
// The include guard is closed here to prevent multiple inclusions of this header file.
#endif // CLIENT_H