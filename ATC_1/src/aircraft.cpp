//#include "aircraft.h"
#include <iostream>
#include <string>
#include <string.h>
#include <thread>
#include "aircraft.h"
#include "Clock.h"
#include <chrono>
using namespace std;

string ID;
//prevClock is to save the last clock value for speed estimations
int arrivalTime, x ,y ,z , xSpeed, ySpeed, zSpeed, prevClock;
Clock * clk;
//thread m_thread;
aircraft::aircraft() {
	// TODO Auto-generated constructor stub
    //m_thread = std::thread(&Clock::run, this);

}
aircraft::aircraft(int arr_time, string id, int x_in, int y_in, int z_in, int speedX, int speedY, int speedZ, Clock * clock_in)
{
	arrivalTime = arr_time;
	prevClock = arrivalTime;
	ID = id;
	x = x_in;
	y = y_in;
	z = z_in;
	xSpeed = speedX;
	ySpeed = speedY;
	zSpeed = speedZ;
	clk = clock_in;
    //m_thread = thread(&aircraft::run);
}

aircraft::~aircraft() {
	// TODO Auto-generated destructor stub
}

void aircraft::test_print()
{
	cout<<"\nArrival Time: "<< arrivalTime;
	cout<<"\nID: "<< ID;
	cout<<"\nX: "<< x;
	cout<<"\nY: "<< y;
	cout<<"\nZ: "<< z;
	cout<<"\nX Speed: "<< xSpeed;
	cout<<"\nY Speed: "<< ySpeed;
	cout<<"\nZ Speed: "<< zSpeed;
}
void aircraft::updatePosition()//
{
	//this->test_print();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	cout<<"\nupdatePosition is being called!";
	int t = clk->count - prevClock;
	prevClock = clk->count;
    x = x + (xSpeed * t)/1000;//dividing by 1000 because we are dealing with ms
    y = y + (ySpeed * t)/1000;
    z = z + (zSpeed * t)/1000;
    cout<<"\n clock count: "<< clk->count;
	this->test_print();
	cout<<"\nthread ID: "<<std::this_thread::get_id();
}

void aircraft::changeSpeed()//when commands are received from the operator console
{

}
void aircraft::run()
{
	while(1 != 0)
	{
		this -> updatePosition();
	}
}

