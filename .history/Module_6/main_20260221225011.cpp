//main cpp file of a client and a server C++ program such that the server computes and sends back to the client the long name of any U.S. state given the two-letter abbreviation.
//The protocol is binary, and is contained in each of the header and cpp files for the client and server.

//!SECTION: The main function starts the server in a separate thread, waits for it to initialize, and then runs the client to interact with the server. The server will be running in an infinite loop to handle multiple client connections sequentially, while the client will allow the user to input state abbreviations and receive the corresponding long names from the server until the user decides to exit the program.

//SECTION - Include necessary header files for the Server and Client classes, as well as standard libraries for input/output operations and threading
// The following libraries are included for socket programming and handling input/output operations
#include "Server.h"
#include "Client.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

// NON-STANDARD PRACTICE: Including cpp files here to work with a generic
// single-file build task. This consolidates all code into one place.
#include "Client.cpp"
#include "Server.cpp"


//SECTION - Definition of the main function
// The main function starts the server in a separate thread, waits for it to initialize, and then runs the client to interact with the server. The server will be running in an infinite loop to handle multiple client connections sequentially, while the client will allow the user to input state abbreviations and receive the corresponding long names from the server until the user decides to exit the program.
int main() {
    //SECTION - Start the server in a separate thread
    // The server is started in a separate thread to allow the main thread to run the client concurrently. The Server object is created with a specified port number (e.g., 8080), and the start method is called in a new thread to run the server. This allows the server to listen for incoming connections while the client is running in the main thread.
    Server server(8080);
    thread serverThread(&Server::start, &server);
    
    //SECTION - Give the server some time to start up
    // A short delay is added to give the server some time to initialize and start listening for incoming connections before the client attempts to connect. This is done using the sleep_for function from the chrono library, which pauses the main thread for a specified duration (e.g., 1 second) to ensure that the server is ready to accept client connections.
    this_thread::sleep_for(chrono::seconds(1));
    
    //SECTION - Run the client to interact with the server
    // The client is run in the main thread to allow user interaction. The Client object is created with the server's IP address (e.g., "127.0.0.1") and port number (e.g., 8080). The run method is called to start the client's interaction with the server, allowing the user to input state abbreviations and receive the corresponding long names from the server until the user decides to exit the program.
    Client client("127.0.0.1", 8080);
    client.run();
    
    //SECTION - Detach the server thread before exiting the main function
    // The server thread is detached before exiting the main function to allow it to continue running independently. Detaching the thread allows the server to keep running in the background even after the main thread (which runs the client) has finished executing. This is done using the detach method of the thread class, which separates the server thread from the main thread and allows it to run without blocking the main thread from exiting.
    serverThread.detach();
    
    //SECTION - Exit program
    // The main function returns 0 to indicate that the program has ended successfully. This is a standard practice in C++ to indicate that the program has completed without errors. The server will continue to run in the background due to the detached thread, but the main thread will exit after the client finishes its execution.
    return 0;
}

//Note: The above code assumes that the Server and Client classes are implemented correctly in their respective header and cpp files, as provided in the previous snippets. The main function starts the server in a separate thread, waits for it to initialize, and then runs the client to interact with the server.