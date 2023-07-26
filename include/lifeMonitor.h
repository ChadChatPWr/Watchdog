# pragma once
#include <iostream>

namespace watchdog{
	
    class lifeMonitor
{

public:
	lifeMonitor();
	~lifeMonitor();

private:
	int watchdogTimer;

	void checkStatus(std::string idComponent);
	void runWatchdogTimer(std::string idComponent);
	void resetWatchdogTimer(std::string idComponent,std::string componentStatus);
	void startDeathManager(std::string idComponent);
};
}