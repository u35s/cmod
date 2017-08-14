#include "./time.h"

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

int nsleep(unsigned long ns){
	struct timespec wait;
	wait.tv_sec = ns / SecondN;
	wait.tv_nsec = ns % SecondN;
	return nanosleep(&wait,NULL);
}

unsigned long xnano(){
	struct timespec ts;
	#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts.tv_sec = mts.tv_sec;
	ts.tv_nsec = mts.tv_nsec;
	#else
	clock_gettime(CLOCK_REALTIME, &ts);
	#endif
	return ts.tv_sec * SecondN + ts.tv_nsec;
}


unsigned long cur(){
	return xnano()/SecondN;
}

Timer::Timer(){

};

Timer::~Timer(){

};

unsigned long Timer::elapse(){
	return xnano() - _last_nano;
};

void Timer::reset(){
	_last_nano=xnano();
};


bool Timer::timeup(unsigned long nano){
	unsigned long v = _last_nano;
	while(nano > v+_interval)
		_last_nano+=_interval;
	return v != _last_nano;
};

