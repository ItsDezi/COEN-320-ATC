
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>
#include "Scheduler.h"
#include "Clock.h"
using namespace std;

std::string get_current_dir() {
   char buff[FILENAME_MAX]; //create string buffer to hold path
   GetCurrentDir( buff, FILENAME_MAX );
   string current_working_dir(buff);
   return current_working_dir;
}

int main() {
	Clock clk;
	//clk.start();
	Scheduler s = Scheduler(&clk);
	   //cout << get_current_dir() << endl;
	while(true)
	{
		if(clk.m_running ==false)
		{
			clk.stop();
		}
		else
		{
			sleep(10);
		}
	}
	return 0;
}
