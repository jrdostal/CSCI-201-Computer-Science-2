//CLient cpp file a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation. The protocol is binary, and is as follows:
//Client connects and sends the two-letter state abbreviation in binary form.
//Client should ask the user for a state abbreviation, read the user input, open a connection to the server, and send the data.
//Client should then read the reply and print it (the long name of the state) to the screen.

//!SECTION: The Client class is defined and implemented in this cpp file. The constructor initializes the client with the server's IP address and port number, while the run method handles the client's interaction with the server. The run method includes initializing Winsock, creating a socket, connecting to the server, sending user input (state abbreviation), receiving the response from the server, and printing it to the screen. The method also includes error handling for socket operations and allows the user to exit the program gracefully.

//SECTION - Include necessary libraries
// The following libraries are included for socket programming and handling input/output operations
#include "Client.h"
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

//SECTION - Definition of the Client class constructor
// Constructor to initialize the client with the server's IP address and port number. The serverIp member variable stores the IP address of the server, and the port member variable stores the port number on which the server is listening for incoming connections. These member variables are initialized in the constructor and used in the run method to establish a connection to the server and communicate with it.
Client::Client(const std::string& serverIp, int port) : serverIp(serverIp), port(port) {}

//SECTION - Definition of the run method for the Client class
// The run method is responsible for connecting to the server, sending state abbreviations, and receiving responses from the server. It initializes Winsock, creates a socket, connects to the server, sends the user input (state abbreviation), receives the response from the server, and prints it to the screen. The method also includes error handling for socket operations and allows the user to exit the program gracefully.
void Client::run() {

    //SECTION - Initialize Winsock
    // The WSAStartup function is called to initialize the Winsock library. It takes a version number (in this case, MAKEWORD(2, 2) for Winsock version 2.2) and a pointer to a WSADATA structure that will receive details about the Windows Sockets implementation. If WSAStartup fails, an error message is printed and the method returns, preventing further execution of the client code.
    WSADATA wsaData;
    // Check if Winsock initialization was successful
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed" << endl;
        return;
    }

    //SECTION - Main loop for client interaction
    // The client enters a loop where it prompts the user to enter a state abbreviation. If the user types "exit", the client will print a message and exit the loop after a countdown. If the user enters a state abbreviation, the client creates a socket, sets up the server address structure, and attempts to connect to the server. If the connection is successful, it sends the abbreviation to the server, waits for a response, and prints the state name received from the server. After handling each request, it closes the socket and continues to prompt the user for input until they choose to exit.
    while (true) {
        //SECTION - Get user input for state abbreviation
        // The user is prompted to enter a state abbreviation or type 'exit' to quit the program. The input is read into the abbreviation variable, which will be used to send the request to the server. If the user types "exit", the client will print a message and exit the loop after a countdown, allowing for a graceful exit from the program.
        string abbreviation;
        // Prompt the user to enter a state abbreviation or type 'exit' to quit the program
        cout << "Enter a state abbreviation (or type 'exit' to quit): ";
        // Read the user input for the state abbreviation
        cin >> abbreviation;

        //SECTION - Check if the user wants to exit the program
        // If the user types "exit", the client will print a message and exit the loop after a countdown. This allows the user to exit the program gracefully, giving them a moment to see the exit message and countdown before the program ends. The countdown is implemented using a for loop that counts down from 10 to 1, with a one-second delay between each number using the sleep_for function from the chrono library.
        // Check if the user wants to exit the program
        if (abbreviation == "exit") {
            // Print a message indicating that the program is exiting and start a countdown before ending the program
            cout << "Now exiting program." << endl;
            // Countdown from 10 to 1 with a one-second delay between each number
            for (int i = 10; i > 0; --i) {
                cout << i << "..." << endl;
                // Sleep for 1 second before printing the next number in the countdown
                this_thread::sleep_for(chrono::seconds(1));
            }
            // Print a final message indicating that the program has ended before breaking out of the loop
            cout << "Program ended." << endl;
            break;
        }

        //SECTION - Create a socket
        // A socket is created for communication with the server using the socket function. The socket is created with the IPv4 address family (AF_INET) and the TCP protocol (SOCK_STREAM). If socket creation fails, an error message is printed and the loop continues, allowing the user to try again. The resulting socket descriptor is stored in the sock variable, which will be used for subsequent communication with the server.
        SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
        // Check if socket creation was successful
        if (sock == INVALID_SOCKET) {
            cerr << "Failed to create socket" << endl;
            break;
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
            continue; // Try again
        }

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

        // Close the socket
        closesocket(sock);
        cout << endl;
    }

    // Cleanup Winsock
    WSACleanup();
}