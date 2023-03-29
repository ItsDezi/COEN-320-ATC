#ifndef MPDATA_H_
#define MPDATA_H_

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>
#include "AircraftData.h"
#include <list>

struct MPData{
	_pulse hdr;
	AircraftData aircraft;
	list<AircraftData> allAircrafts;
};

#endif
