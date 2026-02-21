//main cpp file of a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation.
//The protocol is binary, and is contained in each of the header and cpp files for the client and server.
#include "Server.h"
#include "Client.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Start the server in a separate thread
    Server server(8080);
    thread serverThread(&Server::start, &server);
    
    // Give the server some time to start up
    this_thread::sleep_for(chrono::seconds(1));
    
    // Start the client
    Client client("127.0.0.1", 8080);
    client.run();
    
    // Wait for the server thread to finish
    serverThread.join();
    
    return 0;
}

//Note: The above code assumes that the Server and Client classes are implemented correctly in their respective header and cpp files, as provided in the previous snippets. The main function starts the server in a separate thread, waits for it to initialize, and then runs the client to interact with the server.