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


void watchdog::monitorComponent()
{

}
void watchdog::createComponent(std::string idComponent,std::string componentName){
 component component(idComponent,componentName);
}

watchdog::~watchdog()
{
	std::cout << "stop watchdog" << std::endl;
}
}
