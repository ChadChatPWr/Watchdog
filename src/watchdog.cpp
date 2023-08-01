#include "watchdog.h"

namespace watchdog{



watchdog::watchdog()
{
	std::cout << "start watchdog" << std::endl;
}
void watchdog::setcomponentName(std::string componentName){

    watchdog::componentName = componentName;

}

void watchdog::setidComponent(std::string idComponent){
    watchdog::idComponent = idComponent;
}

std::string watchdog::getcomponentName(){
    return watchdog::componentName;
}

std::string watchdog::getidComponent(){
    return watchdog::idComponent;
}

void watchdog::createComponent(const std::string& idComponent,const std::string& componentName, std::atomic<bool> &shouldClose){

    std::mutex mtx;

    std::lock_guard<std::mutex>lock(mtx);

    std::thread([&]() {
        component component(idComponent,componentName);
        shouldClose = true;

    }).detach();


    while(!shouldClose){
        std::this_thread::yield();
    }
}

void watchdog::monitorComponent()
{

}


watchdog::~watchdog()
{
	std::cout << "stop watchdog" << std::endl;

}
}
