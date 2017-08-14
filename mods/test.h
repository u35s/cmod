#include "../modbase.h"
#include "spdlog/spdlog.h"

class Test : public ModBase {
public:
	Test();
	~Test();
	void init();
	bool wait();
	void run();
	void end();
};
