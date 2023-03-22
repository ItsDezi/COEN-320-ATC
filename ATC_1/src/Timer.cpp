#include "Timer.h"


    Timer::Timer() {
        clock_gettime(CLOCK_REALTIME, &start_time_);
        count = 0;
    }

    void Timer::reset() {
        clock_gettime(CLOCK_REALTIME, &start_time_);
        count = 0;
    }

    double Timer::elapsed() const {
        struct timespec end_time;
        clock_gettime(CLOCK_REALTIME, &end_time);
        return (end_time.tv_sec - start_time_.tv_sec) + (end_time.tv_nsec - start_time_.tv_nsec) / 1000000000.0;
    }

    struct timespec start_time_;

    Timer::~Timer(){

    }

