#include "component.h"
#include "lifeMonitor.h"
#include "deathManager.h"

namespace watchdog{

void component::setComponentStatus(std::string componentStatus){
    component::componentStatus = componentStatus;
}

std::string component::getComponentStatus(){
    return component::componentStatus;
}

component::component(pid_t idComponent, std::string componentName){
    std::cout << "start test component:" << componentName << " with ID = " << idComponent << std::endl;
    std::cout << "id of " << componentName << " thread is:" << std::this_thread::get_id() << std::endl;
    runComponentTimer();
    setComponentStatus("responsive");
    createLifeMonitor(idComponent, componentName,getComponentStatus());

}

void component::createLifeMonitor(pid_t idComponent, std::string componentName, std::string componentStatus){
    lifeMonitor lifeMonitor(idComponent, componentName, componentStatus);
}



void component::runComponentTimer(){
    std::cout << "start component timer" << std::endl;
    start = std::chrono::high_resolution_clock::now();
}

void component::resetComponentTimer(){
    end = std::chrono::high_resolution_clock::now();
    componentTimer = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Components time is " << componentTimer.count() << "(microsec)" << std::endl;
}
component::~component(){

    resetComponentTimer();
	std::cout << "stop test component" << std::endl;

}
}
