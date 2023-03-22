#include "Scheduler.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <list>
#include "aircraft.h"
#include <vector>

using namespace std;

Scheduler::Scheduler(Timer &clock_in) {
	// TODO Auto-generated constructor stub
	clk = &clock_in;
	//sleep(2.4);
	vector<aircraft> aircrafts;
	cout<<"\n scheduler constructor called at: "<<clk->elapsed()<<"\n";
	//clock_in ->set_timer(0, 0, 1, 0);
	//pthread_join(clock_in->m_thread, NULL); // wait for the thread to complete
	  string line,s;
	  ifstream myfile;
	  myfile.open("input.txt");
	  aircraft a;
	  //create_aircraft("hello,");
	  getline(myfile,line);//to ignore first line
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	      //cout << line << '\n';
	      a = create_aircraft(line);
	      //cout<<"\n----------------------\n"<< a.data.ID<<"\n---------------------\n";

	      aircrafts.push_back(a);
	    }
	    myfile.close();
	  }

	  else cout << "Unable to open file";

	  sortAircraftList(aircrafts);
		//aircraft *b;
		//b=&a;
		//thread t(&aircraft::run,a);
		//pthread_create(&a.thread, NULL, aircraft::run, (void *) &a);
}

Scheduler::~Scheduler() {
	// TODO Auto-generated destructor stub
}
void Scheduler::ting()
{
	while(true)
	{
		sleep(1);
		cout<<"\nElapsed time from scheduler:"<<clk->elapsed()<<"\n";
	}
}
aircraft Scheduler::create_aircraft(string s)
{
	int ID;
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
	//cout<<'\n'<<"time: "<<time;

	comma_locations.pop_back();

	int len = comma_locations.back()-temp-1;
	ID = stoi(s.substr(temp+1, len));
	//cout<<'\n'<<"ID: "<<ID;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	x = stoi(s.substr(temp+1, len));
	//cout<<'\n'<<"X: "<<x;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	 y= stoi(s.substr(temp+1, len));
	//cout<<'\n'<<"Y: "<<y;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	z = stoi(s.substr(temp+1, len));
	//cout<<'\n'<<"Z: "<<z;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	speedX = stoi(s.substr(temp+1, len));
	//cout<<'\n'<<"Speed X: "<<speedX;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	 speedY= stoi(s.substr(temp+1, len));
	//cout<<'\n'<<"Speed Y: "<<speedY;
	temp = comma_locations.back();

	comma_locations.pop_back();

	len = comma_locations.back()-temp-1;
	speedZ = stoi(s.substr(temp+1, len));
	//cout<<'\n'<<"Speed Z: "<<speedZ;
	temp = comma_locations.back();

	AircraftData d;
	d = (AircraftData){.ID = ID, .arrivalTime = time, .x = x , .y = y , .z = z , .xSpeed = speedX, .ySpeed = speedY, .zSpeed = speedZ};
	aircraft a = aircraft(d, *clk);
	pthread_t aircraftThread;
    pthread_create(&aircraftThread, NULL, &run_aircraft_update_position, &a);
    pthread_join(aircraftThread, NULL);
	//thread.join();
	//thread h(a.updatePosition(),a);
	//a.test_print();
	//thread a(aircraft(),(time, ID, x, y, z, speedX, speedY, speedZ));//might need to pass params later to give instructions to aircrafts
}

  void* Scheduler::run_aircraft_update_position(void* arg) {
    aircraft* obj = static_cast<aircraft*>(arg);
    //aircraft *obj2 =
    obj->updatePosition();
    return nullptr;
}

  void Scheduler::sortAircraftList(vector<aircraft>& myList) {
	   int i, j,pass=0;
	   aircraft temp;
	   aircraft a[myList.size()-1];
	   for(i = 0; i<myList.size()-1; i++)
	   {
		   a[i] = myList[i];
	   }
	   cout <<"Input list ...\n";
	   for(i = 0; i<myList.size()-1; i++) {
	      cout <<a[i].data.arrivalTime<<"\t";
	   }
	cout<<endl;
	for(i = 0; i<myList.size()-1; i++) {
	   for(j = i+1; j<10; j++)
	   {
	      if(a[j].data.arrivalTime < a[i].data.arrivalTime) {
	         temp = a[i];
	         a[i] = a[j];
	         a[j] = temp;
	      }
	   }
	pass++;
	}
  }
