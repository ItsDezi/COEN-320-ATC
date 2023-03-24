#ifndef SRC_SCHEDULER_H_
#define SRC_SCHEDULER_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <list>
#include <chrono>
#include <pthread.h>
#include "aircraft.h"
#include "Timer.h"
using namespace std;

void create_aircraft(string s);

class Scheduler {
public:
	Timer * clk;
	vector<aircraft> aircrafts;
	//pthread_t[] aircraft_threads;//list of all active aircraft threads to update periodically
	//pthread_t[] unreadyAircrafts
	Scheduler(Timer &clock_in);
	void ting();
	aircraft *sortAircraftList(vector<aircraft> myList);
	//const create_aircraft();
	virtual ~Scheduler();
	aircraft create_aircraft(string s);
	static void* run_aircraft_update_position(void* arg);
};

#endif /* SRC_SCHEDULER_H_ */
