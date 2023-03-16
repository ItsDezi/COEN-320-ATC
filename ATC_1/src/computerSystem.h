#ifndef COMPUTERSYSTEM_H_
#define COMPUTERSYSTEM_H_
#include <iostream>
#include <vector>
#include <thread>
#include <mutex> 
using namespace std;

struct Aircraft {

    int idAircraft;
    int position_x;
    int position_y;
    int position_z; 
}


class ComputerSystem {

private:

	//To calculate and detect Violations
	void computeViolations();

	//To display data on Display Data
	void showDataDisplay();

	//To update period
	void updateAircraftPosition();

	//To emit an alert in case a violation occurs
	void sendViolationAlert();

    void periodicComputations(); 

    //Threads to detect alert to operator: 
    std::thread detectViolations;

    //Boolean function to stop detectViolation Thread: 
    bool falseFlag; 

    //Thread to protect shared data: 
    std::thread aircraftMutex_;

    std::vector<Aircraft> aircraft;



    

public:

	//constructor:
    //We need to know the number of aircrafts in the air to determine if any violations occur 
	ComputerSystem(int numberAircrafts,int periodicComputations);

	//Destructor:
	~ComputerSystem();

    //To start the thread for periodic computations to detect violations
    void startPeriodicComputations(); 

    //To stop the thread for periodic computations to detect violation
    void stopPeriodicComputations(); 



};

#endif

