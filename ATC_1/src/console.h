#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include <queue>
#include <pthread.h>
#include <queue>
#include <pthread.h>

class OperatorConsole {
public:
    OperatorConsole();
    int getMessageChannelId() const;//The messageCahnnelId variable is an integer that represents the channel ID 
                                  //used for communication with the system controller.

    static void* start(void *context);// It is used to start a new thread that runs the startConsole function of an OperatorConsole object.

private:
    private:
    void startConsole();//responsible for initializing the console, creating a new thread for reading user input,
                    // and continuously processing incoming messages from the system controller.
    void handleCommandMessage(); //helper function used by startConsole to handle incoming messages of type OPERATOR_CONSOLE_COMMAND. 

    int messageChannelId; // used for communication with the system controller.Its value is set during the initialization of the OperatorConsole object, and it is used to send and receive messages to and from the system controller.

    static pthread_mutex_t mutex;
    
    static std::queue<ConsoleResponse> responseMessages;//operates on a first-in, first-out (FIFO) basis.//By using a queue to store response messages, the OperatorConsole object can process messages in the order they were received, and ensure that each message is processed exactly once. 
                                                                   //The responseMessages variable is accessed by multiple threads, which is why it is protected by a mutex to prevent synchronization issues.

    static void* readInput(void* arg); //reads user input from the console. 
}
