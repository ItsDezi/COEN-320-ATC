#ifndef SRC_SCHEDULER_H_
#define SRC_SCHEDULER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <list>
#include "Clock.h"
#include <chrono>
#include <thread>
using namespace std;

void create_aircraft(string s);

class Scheduler {
public:
	Clock * clk;
	Scheduler(Clock* clock_in);
	//const create_aircraft();
	virtual ~Scheduler();
	void create_aircraft(string s);

};

#endif /* SRC_SCHEDULER_H_ */
