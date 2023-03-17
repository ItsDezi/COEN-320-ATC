#ifndef SRC_CLOCK_H_
#define SRC_CLOCK_H_
#include <chrono>
#include <thread>
#include <iostream>
class Clock {
public:
	Clock();
	virtual ~Clock();
    std::thread m_thread;
    bool m_running = false;
    std::chrono::steady_clock::time_point m_startTime;
    void run();
    void start();
    void stop();
private:

};

#endif /* SRC_CLOCK_H_ */
