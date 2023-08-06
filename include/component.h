# pragma once
#include <iostream>

#include "watchdog.h"

namespace watchdog{

class component
{
public:

    component(pid_t idComponent, std::string componentName);
    void createLifeMonitor(pid_t idComponent, std::string componentName);
    void setComponentStatus(std::string componentStatus);
    std::string getComponentStatus();
	~component();

private:
	int componentTimer;
    std::string componentStatus;

	void runComponentTimer();
	void resetComponentTimer();
};
}
