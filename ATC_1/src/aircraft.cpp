//#include "aircraft.h"
#include <iostream>
#include <string>
#include <string.h>

#include "Clock.h"
using namespace std;

class aircraft{
string ID;
//prevClock is to save the last clock value for speed estimations
int arrivalTime, x ,y ,z , xSpeed, ySpeed, zSpeed, prevClock;
Clock * clk;
aircraft() {
	// TODO Auto-generated constructor stub


}
aircraft(int arr_time, string id, int x_in, int y_in, int z_in, int speedX, int speedY, int speedZ, Clock * clock_in)
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
}

~aircraft() {
	// TODO Auto-generated destructor stub
}

void test_print()
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
void updatePosition()//
{
	/*t = clk. - prevClock;
    x = x + xSpeed * t;
    y = y + ySpeed * t;
    z = z + zSpeed * t;*/
}

void changeSpeed()//when commands are received from the operator console
{

}
};

