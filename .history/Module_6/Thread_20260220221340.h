//Header file for Thread class created to store the thread and the client socket for each client that connects to the server. This allows the server to handle multiple clients at the same time by creating a new thread for each client that connects.
#ifndef THREAD_H
#define THREAD_H
#include <thread>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

class Thread {
public:
    Thread(SOCKET clientSocket);
    void start();
private:    SOCKET clientSocket;
    thread thread;
    void handleClient();
};

#endif // THREAD_H