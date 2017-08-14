#include <iostream>
#include <vector>
#include "modbase.h"
//typedef unsigned int server_state;

enum ServerStates { INIT,WAIT,RUN,END,STOP };

class Loop {
public:
	Loop();
	~Loop();
	void loop();
	void set_server_state(enum ServerStates s);
private:
	void init();
	bool wait();
	void run();
	void end();
	std::vector<ModBase> 	modVec;	
	ServerStates		state;
	unsigned long 		frame_run_time;
	unsigned long		frame_run_count;
};
 
