/*
 * Radar.cpp
 *
 *  Created on: Mar. 21, 2023
 *      Author: Bisho
 */

#ifndef RADAR_H_
#define RADAR_H_

#include <list>
#include <iostream>
#include "AircraftData.h"
#include <pthread.h>
#include "Server.cpp"
using namespace std;

class Radar {

public:
	// Attributes
	list<AircraftData> allAircrafts;
	list<AircraftData> inRangeAircrafts;
	pthread_t thread;
	// Methods
	Radar(){};
	virtual ~Radar(){};

	static void* detectAircraftsInRange(void* args){


		// Variables
		MPData receivedData;
		int err_no;
		Server RadarServer;
		Radar* radarPointer = (Radar *) args;
		Radar  radar = *radarPointer;
		// Receive a message using message Passing
		err_no = pthread_create(&RadarServer.thread, NULL, Server::serverRoutine, &receivedData); //create the thread
		if (err_no != 0){
			printf("ERROR when creating the Radar Server thread \n");
		}


		// Store it inside Radar.allAircrafts
		radar.allAircrafts = receivedData.allAircrafts;

		// Adding Aircrafts that are in range
		for (AircraftData aircraft : radar.allAircrafts){

			if ((aircraft.x > 0 && aircraft.x <100000)&&
					(aircraft.y > 0 && aircraft.y <100000)&&
					(aircraft.z > 15000 && aircraft.z <40000)){
				radar.inRangeAircrafts.push_back(aircraft);
			}else {
				continue; // not in range
			}
		}


		//TODO: either use message passing to overwrite the old list OR
		for(AircraftData aircraft: radar.inRangeAircrafts){
			cout << aircraft.ID << "is in Range of the Radar"<<endl;
		}


		err_no = pthread_join(RadarServer.thread, NULL); //force the main to wait for the termination of the thread
					if (err_no != 0){
						printf("ERROR when joining the Radar Server thread\n");
					}

		return NULL;
	}

};

#endif /* RADAR_H_ */
