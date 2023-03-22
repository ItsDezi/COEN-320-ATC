#ifndef CTIMER_H_
#define CTIMER_H_

#include <stdio.h>
#include <iostream>
#include <time.h>

#include <sync.h>
#include <sys/siginfo.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <sys/syspage.h>
#include <inttypes.h>
#include <stdint.h>

class cTimer {
	struct sigevent sig_event;
	sigset_t sig_set;
	struct itimerspec timer_spec;
	struct timespec tv;

public:
	timer_t timer_id;
	bool m_running;
	int count;
	cTimer(uint32_t,uint32_t,uint32_t,uint32_t);
	~cTimer();
	void set_timer(uint32_t,uint32_t,uint32_t,uint32_t);
	void wait_next_activation();
	int get_timer_value();
};

#endif /* CTIMER_H_ */
