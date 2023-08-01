#include "deathManager.h"
#include <thread>

namespace watchdog{

deathManager::deathManager(std::string idComponent){
	std::cout << "start test deathManager" << std::endl;
    std::cout << "id of DeathManager of comp id " << idComponent << " thread is:" << std::this_thread::get_id() << std::endl;
}
void deathManager::handleUnresponsive(std::string idComponent){}
void deathManager::kill(std::string idComponent){}
void deathManager::checkIsKIlled(std::string idComponent){}
void deathManager::reset(std::string idComponent){}
deathManager::~deathManager(){
	std::cout << "stop test deathManager" << std::endl;
}
}
