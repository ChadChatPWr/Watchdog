#include "lifeMonitor.h"
#include "component.h"
#include "deathManager.h"

namespace watchdog{

lifeMonitor::lifeMonitor(pid_t idComponent, std::string componentName){
    std::cout << "start LifeMonitor for component:" << componentName << " with ID = " << idComponent << std::endl;
    std::cout << "id LifeMonitors of " << componentName << " thread is:" << std::this_thread::get_id() << std::endl;
    runWatchdogTimer(idComponent);
    checkStatus(idComponent);
}
void lifeMonitor::checkStatus(pid_t idComponent){
    //component::setComponentStatus("unresponsible");
    if(watchdogTimer==5){
        resetWatchdogTimer(idComponent);
    }
    else{
        //startDeathManager(idComponent);
    }
}
int lifeMonitor::runWatchdogTimer(pid_t idComponent){
    std::cout << "Start timer for component with id:" << idComponent << std::endl;
    return watchdogTimer;
}
void lifeMonitor::resetWatchdogTimer(pid_t idComponent){}
//Death manager created by component.cpp
//void lifeMonitor::startDeathManager(pid_t idComponent){
//    //deathManager deathManager();
//}
lifeMonitor::~lifeMonitor(){
	std::cout << "stop test lifeMonitor" << std::endl;
}
}
