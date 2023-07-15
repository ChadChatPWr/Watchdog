#include <iostream>
#include "watchdog.h"


watchdog::watchdog()
{
	std::cout << "start" << std::endl;
}
void watchdog::monitorComponent()
{
}
watchdog::~watchdog()
{
	std::cout << "stop" << std::endl;
}


component::component(){}
void component::runComponentTimer(){}
void component::resetComponentTimer(){}
component::~component(){}

watchdogTimer::watchdogTimer(std::string idComponent){}
void watchdogTimer::resetWatchdogTImer(std::string idComponent,std::string componentStatus){}
watchdogTimer::~watchdogTimer(){}

deathManager::deathManager(){}
void deathManager::handleUnresponsive(std::string idComponent){}
void deathManager::kill(std::string idComponent){}
void deathManager::checkIsKIlled(std::string idComponent){}
void deathManager::reset(std::string idComponent){}
deathManager::~deathManager(){}

lifeMonitor::lifeMonitor(){}
void lifeMonitor::createComponent(std::string idComponent){}
std::string lifeMonitor::checkStatus(std::string idComponent){}
void lifeMonitor::setTimerWatchddog(std::string idComponent){}
void lifeMonitor::startDeathManager(std::string idComponent){}
lifeMonitor::~lifeMonitor(){}
