#ifndef SRC_SCHEDULER_H_
#define SRC_SCHEDULER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <list>
#include "Clock.h"
using namespace std;

void create_aircraft(string s);

class Scheduler {
public:
	Scheduler(Clock* clock_in);
	//const create_aircraft();
	virtual ~Scheduler();
};

#endif /* SRC_SCHEDULER_H_ */
