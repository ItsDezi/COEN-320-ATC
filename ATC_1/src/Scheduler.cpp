#include "Scheduler.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <list>
using namespace std;

Scheduler::Scheduler(Clock* clock_in) {
	// TODO Auto-generated constructor stub
	Clock * clk = clock_in;
	  string line,s;
	  ifstream myfile;
	  myfile.open("input.txt");
	  //create_aircraft("hello,");
	  getline(myfile,line);//to ignore first line
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	      //cout << line << '\n';
	      create_aircraft(line);

	    }
	    myfile.close();
	  }

	  else cout << "Unable to open file";
}

Scheduler::~Scheduler() {
	// TODO Auto-generated destructor stub
}

void create_aircraft(string s)
{
	string ID;
	int time, x, y, z, speedX, speedY, speedZ;
	list<int> comma_locations;
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace),
        s.end());
	for(int i=0;i<s.length();i++)
	{
		//cout<<s[i];
		char c = s[i];

		//int res = c.compare(comma);
		if(c==',')
		{
			comma_locations.push_front(i);
		}
	}
	time = stoi(s.substr(0,comma_locations.back()));
	int temp = comma_locations.back();
	cout<<'\n'<<"time: "<<time;

	comma_locations.pop_back();

	int len = comma_locations.back()-temp-1;
	ID = s.substr(temp+1, len);
	cout<<'\n'<<"ID: "<<ID;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	x = stoi(s.substr(temp+1, len));
	cout<<'\n'<<"X: "<<x;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	 y= stoi(s.substr(temp+1, len));
	cout<<'\n'<<"Y: "<<y;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	z = stoi(s.substr(temp+1, len));
	cout<<'\n'<<"Z: "<<z;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	speedX = stoi(s.substr(temp+1, len));
	cout<<'\n'<<"Speed X: "<<speedX;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	 speedY= stoi(s.substr(temp+1, len));
	cout<<'\n'<<"Speed Y: "<<speedY;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	speedZ = stoi(s.substr(temp+1, len));
	cout<<'\n'<<"Speed Z: "<<speedZ;
	temp = comma_locations.back();

}
