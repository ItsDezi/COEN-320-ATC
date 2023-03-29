/*
 * Timer.h
 *
 *  Created on: Mar. 22, 2023
 *      Author: Julie
 */

#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <sync.h>
#include <sys/siginfo.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <sys/syspage.h>
#include <inttypes.h>
#include <stdint.h>
class Timer {
public:
    Timer();
    int count;
    void reset();

    double elapsed() const;
    virtual ~Timer();
    struct timespec start_time_;

private:
};

#endif /* SRC_TIMER_H_ */
