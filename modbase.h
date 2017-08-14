
class ModBase {
public:
	ModBase(){}
	virtual ~ModBase(){}
	virtual void init(){}
	virtual bool wait(){ return true; }
	virtual void run(){}
	virtual void end(){}
};


