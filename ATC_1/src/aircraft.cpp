//#include "aircraft.h"
#include <iostream>
#include <string>
#include <string.h>
//#include <pthread>
#include "aircraft.h"
#include <chrono>


using namespace std;

//string ID;
//prevClock is to save the last clock value for speed estimations
int arrivalTime, x ,y ,z , xSpeed, ySpeed, zSpeed;//, prevClock;
//Timer * clk;
//thread m_thread;
//AircraftData data;
aircraft::aircraft() {
	// TODO Auto-generated constructor stub
    //m_thread = std::thread(&Clock::run, this);
}
aircraft::aircraft(AircraftData datating, Timer &clock_in)
{
	//const char* ccx = data.ID.c_str();
	//pthread_setname_np(this->thread, ccx);
	data = datating;
	clk = &clock_in;
	prevClock = datating.arrivalTime;
    //m_thread = thread(&aircraft::run);
}

aircraft::~aircraft() {
	// TODO Auto-generated destructor stub
}

void aircraft::test_print()
{
	cout<<"\nArrival Time: "<< data.arrivalTime;
	cout<<"\nID: "<< data.ID;
	cout<<"\nX: "<< data.x;
	cout<<"\nY: "<< data.y;
	cout<<"\nZ: "<< data.z;
	cout<<"\nX Speed: "<< data.xSpeed;
	cout<<"\nY Speed: "<< data.ySpeed;
	cout<<"\nZ Speed: "<< data.zSpeed;
}
 void* aircraft::updatePosition(void* args)//
{
	aircraft* a = (aircraft*) args;
	//aircraft a = *c;
	//aircraft *a = this;
	//this->test_print();
	//a->test_print();
	cout<<"\nupdatePosition is being called!";
    //sleep(2);
	int t = a->clk->count - a->prevClock;//PROBLEM?!?!?!?!?
    //cout<<"\n clock from aircraft is: "<< a->clk->elapsed();
    //cout<<"\n previous clock count: "<< a->prevClock;
	a->prevClock = a->clk->elapsed();
	a->data.x = a->data.x + (a->data.xSpeed * t)/1000;//dividing by 1000 because we are dealing with ms
	a->data.y = a->data.y + (a->data.ySpeed * t)/1000;
	a->data.z = a->data.z + (a->data.zSpeed * t)/1000;
	//a->test_print();
	//cout<<"\nthread ID: "<<pthread_self();



}

void aircraft::changeSpeed()//when commands are received from the operator console
{

}
void* aircraft::run(void *a)
{
	while(1 != 0)
	{
		//updatePosition(a);
	}
}

