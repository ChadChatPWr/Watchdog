#include "deathManager.h"
#include <thread>

namespace watchdog{

deathManager::deathManager(pid_t idComponent){
	std::cout << "start test deathManager" << std::endl;
    std::cout << "id of DeathManager of comp id " << idComponent << " thread is:" << std::this_thread::get_id() << std::endl;
}
void deathManager::handleUnresponsive(pid_t idComponent){}
void deathManager::kill(pid_t idComponent){}
void deathManager::checkIsKIlled(pid_t idComponent){}
void deathManager::reset(std::string componentName){

    const char* pathDataProcessor = "";  //path to DataProcessor script
    const char* pathBackendProcessor = "";  //path to BackendProcessor
    //const char* pathBackendProcessor = "/home/boris/Documents/messageserver/build/deploy/message_server";
    const char* path;

    if(componentName == "1"){                  // later compare name of component
        path = pathBackendProcessor;
    }
    else if(componentName == "2"){
        path = pathDataProcessor;
    }

    int result = system(path);

    if(result == 0){
        std::cout << "Run" << std::endl;
    }
    else{
        std::cout << "something wrong" << std::endl;
    }
}
deathManager::~deathManager(){
	std::cout << "stop test deathManager" << std::endl;
}
}
