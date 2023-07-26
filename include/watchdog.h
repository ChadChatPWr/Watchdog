# pragma once
#include <iostream>

namespace watchdog{
	
    class watchdog
{
public:
	std::string idComponent;
	std::string componentName;

	watchdog();
	~watchdog();
	void monitorComponent();

private:


	//void createComponent(const std::vector<std::string>& messages);
	void createComponent(std::string jsonMessage);
	void createLifeMonitor(std::string idComponent);
};
}