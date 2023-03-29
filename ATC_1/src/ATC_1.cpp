
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>
#include "Scheduler.h"
#include "Timer.h"

using namespace std;

void* run_timer(void* arg) {
    Timer* timer = static_cast<Timer*>(arg);
    double elapsed_time;
    // Do some work here...
    while (true) {
    	sleep(1);
        elapsed_time = timer->elapsed();
        //std::cout << "Elapsed time: " << timer->elapsed() << " seconds\n";
        //cout << "\n" <<x << "\n";

    }

    //elapsed_time = timer->elapsed();
    //std::cout << "Elapsed time: " << elapsed_time << " seconds\n";

    return NULL;
}
static void* run_scheduler(void* arg) {
    Scheduler* obj = static_cast<Scheduler*>(arg);
    obj->ting();
    return nullptr;
}

int main() {

    pthread_t timerThread;
    pthread_t schedulerThread;

    Timer *timer = new Timer();
    //Timer timer;
	Scheduler s = Scheduler(*timer);
    pthread_create(&timerThread, NULL, &run_timer, &timer);
    pthread_create(&schedulerThread, NULL, &run_scheduler,&s);
	//cout<<"\nTimer count from main is:"<<timer->count<<"\n";
    while(true)
    {
    	sleep(1);
    }
    pthread_join(schedulerThread, NULL);
    pthread_join(timerThread, NULL);
    timer->~Timer();
    s.~Scheduler();

	return 0;
}

