#include "OperatingConsole.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include "Client.cpp"

void OperatingConsole::run() {
    Command command;

    // Read input from the user
    cout << "Enter 0 to read object, 1 to change object: ";
    cin >> command.readOrChange;
    
    cout << "Enter attribute to read or change:\n";
    cout << "1 - x\n";
    cout << "2 - y\n";
    cout << "3 - z\n";
    cin >> command.attributes;

    cout << "Enter aircraft ID: ";
    cin >> command.ID;

    if (command.readOrChange == 1) {
        cout << "Enter new value: ";
        cin >> command.newValue;
    }
    
    static void* computerSystem(void* args){
        
        MPData sendData;
        
    // Output the command
   }
 }

void *OperatingConsole::runThread(void *arg) {
    OperatingConsole *console = (OperatingConsole*)arg;
    console->run();
    return NULL;
}
