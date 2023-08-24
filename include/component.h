# pragma once
#include <iostream>
#include <chrono>

#include "watchdog.h"

namespace watchdog{

class component
{
public:

    component(pid_t idComponent, std::string componentName);

   // void createDeathManager(pid_t idComponent, std::string componentName);
    void setComponentStatus(std::string componentStatus);
    std::string getComponentStatus();
	~component();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start ,end;
    std::chrono::microseconds componentTimer;
    //int componentTimer;
    std::string componentStatus;

    void createLifeMonitor(pid_t idComponent, std::string componentName, std::string componentStatus);
	void runComponentTimer();
	void resetComponentTimer();
};
}
