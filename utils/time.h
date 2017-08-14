#include <sys/time.h>

const unsigned long	Nanosecond	      = 1;					 //纳秒 ns
const unsigned long	MicrosecondN      = 1000 * Nanosecond; 	 //微妙 us
const unsigned long	MillisecondN      = 1000 * MicrosecondN; //毫秒 ms
const unsigned long	SecondN           = 1000 * MillisecondN;
const unsigned long	MinuteN           = 60 * SecondN;

const unsigned long	SecondS = 1;
const unsigned long	MinuteS = 60 * SecondS;
const unsigned long	HourS   = 60 * MinuteS;
const unsigned long	DayS    = 24 * HourS;
const unsigned long	WeekS   = 7 * DayS;
const unsigned long	MonthS  = 30 * DayS;

int nsleep(unsigned long ns);
unsigned long xnano();	
unsigned long xcur();

class Timer{
public:
	Timer();
	~Timer();
	void reset();
	unsigned long elapse();
	bool timeup(unsigned long nano);

private:
	unsigned long _last_nano;
	unsigned long _interval;
};
