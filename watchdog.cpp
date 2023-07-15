#include <iostream>
#include "watchdog.h"


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


component::component(){
	std::cout << "start test component" << std::endl;
}
void component::runComponentTimer(){}
void component::resetComponentTimer(){}
component::~component(){
	std::cout << "stop test component" << std::endl;
}


deathManager::deathManager(){
	std::cout << "start test deathManager" << std::endl;
}
void deathManager::handleUnresponsive(std::string idComponent){}
void deathManager::kill(std::string idComponent){}
void deathManager::checkIsKIlled(std::string idComponent){}
void deathManager::reset(std::string idComponent){}
deathManager::~deathManager(){
	std::cout << "stop test deathManager" << std::endl;
}

lifeMonitor::lifeMonitor(){
	std::cout << "start test lifeMonitor" << std::endl;
}
std::string lifeMonitor::checkStatus(std::string idComponent){}
void lifeMonitor::runWatchdogTimer(std::string idComponent){}
void lifeMonitor::resetWatchdogTimer(std::string idComponent,std::string componentStatus){}
void lifeMonitor::startDeathManager(std::string idComponent){}
lifeMonitor::~lifeMonitor(){
	std::cout << "stop test lifeMonitor" << std::endl;
}
