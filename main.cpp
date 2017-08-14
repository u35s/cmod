#include "loop.h"
#include "spdlog/spdlog.h"

int main(int argc,char* argv[]){
	spdlog::stdout_logger_mt("console");
	Loop loop;
	loop.loop();
	return 0;
}
