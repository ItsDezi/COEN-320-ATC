#ifndef COMPUTERSYSTEM_H_
#define COMPUTERSYSTEM_H_
#include <iostream>
#include <vector>
#include <pthread.h>
#include <mutex> 
#include <AircraftData.h>
//h file radar
using namespace std;


class ComputerSystem {

public:

    //constructor: We need to know the number of aircrafts in the air to determine if any violations occur 
	ComputerSystem(Radar& radar, int numberAircrafts, int periodicComputations);
	
    //Destructor:
	~ComputerSystem();
    
    //To start the pthread for periodic computations to detect violations
    void startPeriodicComputations(); 
    
    //To stop the pthread for periodic computations to detect violation
    void stopPeriodicComputations(); 

	//To calculate and detect Violations
	void computeViolations();
	
    //To display data on Display Data
	void showDataDisplay();
	
    //To update period
	void updateAircraftPosition();
	
    //To emit an alert in case a violation occurs
	void sendViolationAlert();
   
    //To calculate periodic computations
    void periodicComputations(); 
   
    //To send updated Data to data display
    void sendDataToDataDisplay(int ID,int x,int y,int z);

    //pthread to detect alert to operator: 
    pthread_t detectViolations;
   
    //Boolean function to stop detectViolation Thread: 
    bool falseFlag; 
   
    //pthread to protect shared data: 
    pthread_t aircraftMutex_;
    vector<Aircraft> aircraft;
    
	

};

#endif
