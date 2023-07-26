#include "lifeMonitor.h"

namespace watchdog{

lifeMonitor::lifeMonitor(){
	std::cout << "start test lifeMonitor" << std::endl;
}
void lifeMonitor::checkStatus(std::string idComponent){}
void lifeMonitor::runWatchdogTimer(std::string idComponent){}
void lifeMonitor::resetWatchdogTimer(std::string idComponent,std::string componentStatus){}
void lifeMonitor::startDeathManager(std::string idComponent){}
lifeMonitor::~lifeMonitor(){
	std::cout << "stop test lifeMonitor" << std::endl;
}
}