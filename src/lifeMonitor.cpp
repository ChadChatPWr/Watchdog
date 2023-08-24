#include "lifeMonitor.h"
#include "component.h"
#include "deathManager.h"

namespace watchdog{

lifeMonitor::lifeMonitor(pid_t idComponent, std::string componentName, std::string componentStatus){
    std::cout << "start LifeMonitor for component:" << componentName << " with ID = " << idComponent << std::endl;
    std::cout << "id LifeMonitors of " << componentName << " thread is:" << std::this_thread::get_id() << std::endl;
    runWatchdogTimer(idComponent);
    checkStatus(idComponent, componentName, componentStatus);
}

void lifeMonitor::checkStatus(pid_t idComponent, std::string componentName, std::string componentStatus){

    while (componentStatus=="responsive") {

        //here will send massege to component

        std::this_thread::sleep_for(std::chrono::seconds(2));

        if(!1){    // here while check if component answer
            std::cout << "Status is unresponsive" << std::endl;
            startDeathManager(idComponent, componentName);
            break;
        }
        else{
            std::cout << "Status is responsive" << std::endl;
        }

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

void lifeMonitor::startDeathManager(pid_t idComponent, std::string componentName){
    deathManager deathManager(idComponent, componentName);

}

lifeMonitor::~lifeMonitor(){
	std::cout << "stop test lifeMonitor" << std::endl;
}
}
