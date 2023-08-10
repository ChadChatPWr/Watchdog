#include "watchdog.h"

namespace watchdog{



watchdog::watchdog()
{
	std::cout << "start watchdog" << std::endl;
}
void watchdog::setcomponentName(std::string componentName){

    watchdog::componentName = componentName;

}

void watchdog::setidComponent(pid_t idComponent){
    watchdog::idComponent = idComponent;
}

std::string watchdog::getcomponentName(){
    return watchdog::componentName;
}

pid_t watchdog::getidComponent(){
    return watchdog::idComponent;
}

void watchdog::createComponent(const pid_t& idComponent,const std::string& componentName, std::atomic<bool> &shouldClose){

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

    std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "stop watchdog" << std::endl;

}
}
