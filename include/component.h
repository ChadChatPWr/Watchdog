# pragma once
#include <iostream>

namespace watchdog{

class component
{
public:
	std::string componentStatus;

	component(std::string idComponent, std::string componentName);
	~component();

private:
	int componentTimer;

	void runComponentTimer();
	void resetComponentTimer();
};
}