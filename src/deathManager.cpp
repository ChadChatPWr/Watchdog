#include "deathManager.h"

namespace watchdog{

deathManager::deathManager(){
	std::cout << "start test deathManager" << std::endl;
}
void deathManager::handleUnresponsive(std::string idComponent){}
void deathManager::kill(std::string idComponent){}
void deathManager::checkIsKIlled(std::string idComponent){}
void deathManager::reset(std::string idComponent){}
deathManager::~deathManager(){
	std::cout << "stop test deathManager" << std::endl;
}
}