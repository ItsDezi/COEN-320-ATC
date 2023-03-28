// #include "computerSystem.h"
// #include <iostream>
// #include <pthread.h>
// #include <mutex>
// #include <AircraftData.h>
// //include header radar.h
// using namespace std;


// //Constructor:
// // this is the function that must be used when I have the radar class from beshoi's code

// ComputerSystem::ComputerSystem(Radar& radar, int numberAircrafts, int periodicComputations ) {
//     //Retrieve Information about aircraft from radar: 
//         aircraft.resize(numberAircrafts); 
//         for (int i = 0; i < numberAircrafts; i++){
//             aircraftInformation info = radar.getAircraftInformation(i);
//             aircraft[i].ID = info.ID;
//             aircraft[i].x = info.x;
//             aircraft[i].y = info.y;
//             aircraft[i].z = info.z;
//         }
//         //to turn off:
//         falseFlag = false;
//  }

// //Destructor
// ComputerSystem::~ComputerSystem(){
//     //use stop to stop the function called detectViolations
//     stopPeriodicComputations();
// }

// //Function to start Periodic Computation to check for violations
// void ComputerSystem::startPeriodicComputations(){
//    pthread_create(&detectViolations, NULL, &ComputerSystem::computeViolations,this);
// }

// //Function to stop Periodic Computation to check for violations
// void ComputerSystem::stopPeriodicComputations(){
//     falseFlag = true;

//     pthread_join(detectViolations,NULL);

// }

// //Function to compute violations
// void* ComputerSystem::computeViolations(){
//     while(falseFlag == false) {
        
//         // to check for Violations: 
//         for (int i =0; i < aircraft.size(); i++ ){
//             for (int j = i+1; j < aircraft.size();j++){

//                 int position_x = abs(aircraft[i].x - aircraft[j].x ); 
//                 int position_y = abs(aircraft[i].y - aircraft[j].y ) ; 
//                 int position_z = abs(aircraft[i].z - aircraft[j].z ); 

//                 if (position_x < 3000 || position_y < 3000 || position_z < 1000){
//                       cout << "Danger! Safety Violation Detected Aircrafts  "<<aircraft[i].ID << " and " <<
//                         aircraft[j].ID << " are  close" << endl;

//                 }
//                 //Show axis violation: 
//                     if (position_x < 3000){
//                     cout<<"Violation is on X-axis" << endl;
//                     }
//                     if(position_y < 3000){
//                         cout << "Violation on Y-axis" << endl; 
//                     }
//                     if( position_z < 1000){
//                         cout << "Violation on Z-axis" << endl; 
//             }
//         }
//      }
// }

// //Function to send data to data display; 
// void ComputerSystem::sendDataToDataDisplay(int ID, int x, int y,int z){
// string data = "Aircraft " + to_string(ID) + " is at position (" + to_string(x) 
// + ", " + to_string(y) + ", " + to_string(z) + ")";

// // Send the data to the data display
// cout << "Sending data to data display: " << data << endl;

// }

// }




