//CLient header file of a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation. The protocol is binary, and is as follows:
//Client connects and sends the two-letter state abbreviation in binary form.
//Client should ask the user for a state abbreviation, read the user input, open a connection to the server, and send the data.
//Client should then read the reply and print it (the long name of the state) to the screen.
#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

class Client {
public:
    Client(const string& serverIp, int port);
    void run();
private:
    string serverIp;
    int port;
};

#endif // CLIENT_H