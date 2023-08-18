# pragma once
#include <iostream>

namespace watchdog{

class deathManager
{

public:
	deathManager(pid_t idComponent, std::string componentName);
	~deathManager();

private:
	void handleUnresponsive(pid_t idComponent);
	void killThread(pid_t idComponent);
	bool checkIsKilled(pid_t idComponent);
	void reset(pid_t idComponent);
};
}
