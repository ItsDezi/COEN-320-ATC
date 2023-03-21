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
#include <thread>
#include "aircraft.h"
#include "Clock.h"
#include <chrono>
using namespace std;

class aircraft {
public:
	Clock * clk;
	string ID;
	//thread m_thread;
	aircraft();
	virtual ~aircraft();
	aircraft(int arr_time, string id, int x_in, int y_in, int z_in, int speedX, int speedY, int speedZ, Clock * clock_in);
	void test_print();
	void updatePosition();
	void changeSpeed();
	void run();

};

#endif /* SRC_AIRCRAFT_H_ */
