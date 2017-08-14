#include <iostream>
#include <unistd.h>
#include "loop.h"
#include "utils/time.h"
#include "spdlog/spdlog.h"

using namespace std;

Loop::Loop():state(INIT),frame_run_time(SecondN){
	
}

Loop::~Loop(){
	
}

void Loop::set_server_state(enum ServerStates s){
	state=s;
}

void Loop::init(){
	spdlog::get("console")->info("init");
}

bool Loop::wait(){
	spdlog::get("console")->info("wait");
	return true;
}


void Loop::run(){
	spdlog::get("console")->info("run");
}

void Loop::end(){
	spdlog::get("console")->info("end");
}

void Loop::loop(){
	Timer timer;
	unsigned long sleep_time,elapse_time;
	while(state != STOP){
		timer.reset();
		switch (state){
			case INIT:	
				init();
				set_server_state(WAIT);
				break;
			case WAIT:	
				if (wait())
					set_server_state(RUN);
				break;
			case RUN:	
				run();
				break;
			case END:	
				end();
				set_server_state(STOP);
				break;
			case STOP:
				break;
		}
		elapse_time = timer.elapse();
		if(elapse_time < frame_run_time){
			sleep_time = frame_run_time -  elapse_time;
			nsleep(sleep_time);
			spdlog::get("console")->info("now: {:d},runing time sleep {:d} ns",xnano(),sleep_time);
			//cout << "now: " << xnano() << ",runing time sleep " << sleep_time << " ns," << endl;	
		}else{
			cout << "runing time more than " << (elapse_time-frame_run_time) << " ns" << endl;	
		};
	}
}
