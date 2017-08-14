#include "./test.h"
#include "spdlog/spdlog.h"

Test::Test(){
	spdlog::get("console")->info("test created");
};


Test::~Test(){
	spdlog::get("console")->info("test destory");
};


void Test::init(){
	spdlog::get("console")->info("test init");
};


bool Test::wait(){
	spdlog::get("console")->info("test wait");
	return true;
};


void Test::run(){
	spdlog::get("console")->info("test run");
};


void Test::end(){
	spdlog::get("console")->info("test end");
};
