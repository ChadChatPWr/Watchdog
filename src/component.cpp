#include "component.h"
#include "lifeMonitor.h"

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
    createLifeMonitor(idComponent, componentName);
    setComponentStatus("running");
    runComponentTimer();
}

void component::createLifeMonitor(pid_t idComponent, std::string componentName){
    lifeMonitor lifeMonitor(idComponent, componentName);
}

void component::runComponentTimer(){
    std::cout << "start component timer" << std::endl;
}

void component::resetComponentTimer(){}
component::~component(){
	std::cout << "stop test component" << std::endl;
}
}
