#include <iostream>
#include <unistd.h>
#include "loop.h"
#include "utils/time.h"
#include "spdlog/spdlog.h"

using namespace std;

Loop::Loop():state(INIT),frame_run_time(SecondN),
	frame_run_count(0){
	
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
	if (frame_run_count % 60 == 0)
		spdlog::get("console")->info("run");
	frame_run_count++;
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
			//spdlog::get("console")->info("now: {:d},runing time sleep {:d} ns",xnano(),sleep_time);
		}else{
			spdlog::get("console")->info("runing time more than {:d} ns",elapse_time-frame_run_time);
		};
	}
}
