#include "loop.h"
#include "mods/test.h"
#include "spdlog/spdlog.h"

Loop* loop; 

void signalHandler(int signum) {
	spdlog::get("console")->info("get signal {:d}",signum);
	loop->set_server_state(END);	
};

int main(int argc,char* argv[]){
	spdlog::stdout_logger_mt("console");

	loop=new(Loop);
	loop->add_mod(new(Test));

 	signal(SIGINT, signalHandler);

	loop->loop();
	return 0;
}
