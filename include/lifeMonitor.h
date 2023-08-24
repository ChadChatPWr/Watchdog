# pragma once
#include <iostream>

namespace watchdog{
	
    class lifeMonitor
{

public:
    lifeMonitor(pid_t idComponent, std::string componentName, std::string componentStatus);
	~lifeMonitor();

private:
	int watchdogTimer;

    void checkStatus(pid_t idComponent, std::string componentName, std::string componentStatus);
    int runWatchdogTimer(pid_t idComponent);
    void resetWatchdogTimer(pid_t idComponent);
    void startDeathManager(pid_t idComponent,std::string componentName);
};
}
