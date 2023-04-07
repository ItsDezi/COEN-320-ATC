
#include "OperatingConsole.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include "Client.cpp"


   void OperatingConsole::writeToFile( string fileName, vector<Command>) commands{
  
  
    
    // Write data to output file
    ofstream oFile(fileName);
     
    //string commandReadOrChange;
   
    //string commandattributes;
    
    //string commandString;
     string newValue;
    
    // Write to the file
    for(int i=0;i<commands.size();i++){
        
        string commandReadorChange;
        
        if(commands[i].readOrChange == 0)
            commandReadOrChange = "Read";
        else if(commands[i].readOrChange == 1)
            commandReadOrChange = "change";
        else
            commandReadOrChange = "Error no read nor change";
            
        string commandAttributes;
        if(commands[i].attributes == 1)
            commandAttributes = "x speed";
        else if(commands[i].attributes == 2)
            commandAttributes = "y speed";
        else if(commands[i].attributes == 3)
            commandAttributes = "z speed";
        else
            commandAttributes = "Error: unknown attribute";
            
        string commandString;    
        if (commands[i].readOrChange == 0)
        commandString = "ID: " + to_string(commands[i].ID) + ", Command: " + commandReadOrChange;
     
        else if (commands[i].readOrChange == 1)
          commandString = "ID: " + to_string(commands[i].ID) + ", Command: " + commandReadOrChange + ", Attribute: " + commandAttributes + "new value: " + to_string(commands[i].newValue) ;
        
        
        oFile <<commandString<< endl;
    }
    
    // Close the file
    oFile.close();

    
    
    
    // Write data to output file
    //data.writeToFile("command.txt", vector<string> userString);
   }
    
    void *OperatingConsole::run( void *arguments) {
       
     Command *commandPointer = (command *)arguments;
     Command command = (*commandPointer);
    // Read input from the user
    cout << "Enter 0 to read object, 1 to change object: "<< endl;
    cin >> command.readOrChange;
    
    cout << "Enter attribute to read or change:\n";
    cout << "1 - x\n";
    cout << "2 - y\n";
    cout << "3 - z\n";
    cin >> command.attributes;

    cout << "Enter aircraft ID: ";
    cin >> command.ID;

    if (command.readOrChange == 1) {
        cout << "Enter new value: "<<endl;
        cin >> command.newValue;
        
    pthread_exit(NULL);
    return NULL;
    }
    
    //static void* computerSystem(void* args){
        
      void OperatingConsoleClient(MPData MsgToSend){

		int server_coid; //server connection ID.  // change channel name 
		if ((server_coid = name_open(MsgToSend.channelName.c_str(), 0)) == -1) {
			perror("Error occurred while attaching the channel");
		}

		if (MsgSend(server_coid, &MsgToSend, sizeof(MsgToSend), NULL,0) == -1) {
			printf("Error while sending the message from Client");
		}

	};

   };
   
   #endif





