# pragma once
#include <iostream>

namespace watchdog{
	
    class lifeMonitor
{

public:
    lifeMonitor(std::string idComponent, std::string componentName);
	~lifeMonitor();

private:
	int watchdogTimer;

	void checkStatus(std::string idComponent);
    int runWatchdogTimer(std::string idComponent);
    void resetWatchdogTimer(std::string idComponent);
	void startDeathManager(std::string idComponent);
};
}
