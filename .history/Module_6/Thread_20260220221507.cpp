//Cpp file for Thread class created to store the thread and the client socket for each client that connects to the server. This allows the server to handle multiple clients at the same time by creating a new thread for each client that connects.
#include "Thread.h"
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

Thread::Thread(SOCKET clientSocket) : clientSocket(clientSocket) {}

void Thread::start() {
    thread = thread(&Thread::handleClient, this);
}

void Thread::handleClient() {
    char buffer[1024] = {0};
    int bytesReceived = recv(clientSocket, buffer, 1024, 0);
    if (bytesReceived > 0) {
        string abbreviation(buffer, bytesReceived);
        cout << "Received abbreviation: " << abbreviation << endl;
        // Here you would look up the abbreviation in the state map and send back the long name
        // For simplicity, we'll just echo back the abbreviation for now
        send(clientSocket, buffer, bytesReceived, 0);
    } else {
        cerr << "Failed to receive data from client" << endl;
    }
    closesocket(clientSocket);
}