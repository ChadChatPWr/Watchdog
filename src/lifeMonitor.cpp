#include "lifeMonitor.h"
#include "component.h"
#include "deathManager.h"

namespace watchdog{

lifeMonitor::lifeMonitor(std::string idComponent, std::string componentName){
    std::cout << "start LifeMonitor for component:" << componentName << " with ID = " << idComponent << std::endl;
    runWatchdogTimer(idComponent);
    checkStatus(idComponent);
}
void lifeMonitor::checkStatus(std::string idComponent){
    //component::setComponentStatus("unresponsible");
    if(watchdogTimer==5){
        resetWatchdogTimer(idComponent);
    }
    else{
        startDeathManager(idComponent);
    }
}
int lifeMonitor::runWatchdogTimer(std::string idComponent){
    std::cout << "Start timer for component with id:" << idComponent << std::endl;
    return watchdogTimer;
}
void lifeMonitor::resetWatchdogTimer(std::string idComponent){}
void lifeMonitor::startDeathManager(std::string idComponent){
    deathManager deathManager(idComponent);
}
lifeMonitor::~lifeMonitor(){
	std::cout << "stop test lifeMonitor" << std::endl;
}
}
