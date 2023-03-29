#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
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
    
   
}
