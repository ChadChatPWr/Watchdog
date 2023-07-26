#include "component.h"

namespace watchdog{

component::component(std::string idComponent, std::string componentName){
	std::cout << "start test component:" << componentName << std::endl << "with ID = " << idComponent << std::endl;
}
void component::runComponentTimer(){}
void component::resetComponentTimer(){}
component::~component(){
	std::cout << "stop test component" << std::endl;
}
}