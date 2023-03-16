/*
 * Scheduler.h
 *
 *  Created on: Mar. 13, 2023
 *      Author: Julie
 */

#ifndef SRC_SCHEDULER_H_
#define SRC_SCHEDULER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <list>
using namespace std;

void create_aircraft(string s);

class Scheduler {
public:
	Scheduler();
	//const create_aircraft();
	virtual ~Scheduler();
};

#endif /* SRC_SCHEDULER_H_ */
