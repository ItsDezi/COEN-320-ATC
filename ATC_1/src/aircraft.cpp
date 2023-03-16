/*
 * aircraft.cpp
 *
 *  Created on: Mar. 16, 2023
 *      Author: Julien
 */

//#include "aircraft.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class aircraft{
string ID;
int arrivalTime,x,y,z,xSpeed,ySpeed,zSpeed;
aircraft() {
	// TODO Auto-generated constructor stub


}
aircraft(int arr_time, string id, int x_in, int y_in, int z_in, int speedX, int speedY, int speedZ)
{
	arrivalTime = arr_time;
	ID = id;
	x = x_in;
	y = y_in;
	z = z_in;
	xSpeed = speedX;
	ySpeed = speedY;
	zSpeed = speedZ;
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
};

