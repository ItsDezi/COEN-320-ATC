#include "computerSystem.h"
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


//Constructor:
// this is the function that must be used when I have the radar class from beshoi's code
ComputerSystem::ComputerSystem(Radar& radar, int numberAircrafts, int periodicComputations ) {

    //Retrieve Information about aircraft from radar: 
        aircraft.resize(numberAircrafts); 
        for (int i = 0; i < numberAircrafts; i++){
            aircraftInformation info = radar.getAircraftInformation(i);
            aircraft[i].idAircraft = info.idAircraft;
            aircraft[i].position_x = info.position_x;
            aircraft[i].position_y = info.position_y;
            aircraft[i].position_z = info.position_z;
        }
        periodicComputations =  periodicComputations;
        falseFlag = false;
 }

//Destructor
ComputerSystem::~ComputerSystem(){
    //use stop to stop the function called detectViolations
    stopPeriodicComputations();
}

//Function to start Periodic Computation to check for violations
void ComputerSystem::startPeriodicComputations(){
    detectViolations = std::thread(&ComputerSystem::computeViolations,this);

}

//Function to stop Periodic Computation to check for violations
void ComputerSystem::stopPeriodicComputations(){
    falseFlag = true;
    if (detectViolations.joinable()){
        detectViolations.join();
    }
}

//Function to compute violations
void ComputerSystem::computeViolations(){
    while(falseFlag = false) {
        
        // to check for Violations: 
        for (int i =0; i < aircraft.size(); i++ ){
            for (int j = i+1; j < aircraft.size();j++){
                if ( abs(aircraft[i].position_x - aircraft[j].position_x < 3000 &&
                     abs(aircraft[i].position_y - aircraft[j].position_y < 3000 &&
                     abs(aircraft[i].position_z - aircraft[j].position_z < 1000)))){
                        std::cout << "Danger! Safety Violation Detected Aircrafts  "<<aircraft[i].idAircraft << " and " <<
                        aircraft[j].idAircraft << " are  close" << std::endl;
                     } 
            }
        }

    }
}



