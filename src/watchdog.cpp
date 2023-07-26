#include "watchdog.h"

namespace watchdog{

watchdog::watchdog()
{
	std::cout << "start watchdog" << std::endl;
}
void watchdog::monitorComponent()
{
}
void watchdog::createComponent(std::string idComponent){}
void watchdog::createLifeMonitor(std::string idComponent){}
watchdog::~watchdog()
{
	std::cout << "stop watchdog" << std::endl;
}
}