/*
 * aircraft.h
 *
 *  Created on: Mar. 20, 2023
 *      Author: Julie
 */

#ifndef SRC_AIRCRAFT_H_
#define SRC_AIRCRAFT_H_
#include <iostream>
#include <string>
#include <string.h>
#include <pthread.h>
#include "aircraft.h"
#include <chrono>
#include "AircraftData.h"
#include "Timer.h"
#include <unistd.h>
using namespace std;

class aircraft {
public:
	Timer * clk;
	int ID;
	//thread m_thread;
	aircraft();
	pthread_t thread;
	virtual ~aircraft();
	AircraftData data;
	double prevClock;
	aircraft(AircraftData dataTing, Timer &clock_in);
	void test_print();
	void* updatePosition();
	void changeSpeed();
	static void* run(void *a);

};

#endif /* SRC_AIRCRAFT_H_ */
