#include "deathManager.h"
#include <signal.h> //Lib for kill function

namespace watchdog{

deathManager::deathManager(){
	std::cout << "start test deathManager" << std::endl;
}

//Check if PID is killed, return false if its still running, return true if it isnt running
bool deathManager::checkIsKilled(pid_t idComponent){
	if(0==kill(idComponent, 0)){
		//Still running
		std::cout<<"Thread with PID number "<<idComponent<<" is still running."<<std::endl;
		return false;
	}else{
		//Not running
		std::cout<<"Thread with PID number "<<idComponent<<" is not running."<<std::endl;
		return true;
	}
}

void deathManager::handleUnresponsive(pid_t idComponent){
	//Check if the PID is correct
	if(idComponent){
		//Check if PID is running
		if(checkIsKilled(idComponent)==true){
			//PID not running, restart the process
			std::cout<<"PID not running, restarting the process"<<std::endl;
			reset(idComponent);
		}else{
			//PID running, but unresponsive, kill the PID
			std::cout<<"PID runnning, but unresponsive, killing the thread"<<std::endl;
			killThread(idComponent);
		}
	}
	
}

//idComponent is passed on as pid_t, so that the kill function from signal.h library can work correctly.
void deathManager::killThread(pid_t idComponent){
	std::cout<<"Attempting to kill thread with PID number "<<idComponent<<std::endl;
		if(idComponent){
			if(kill(idComponent, SIGTERM)==0){
				//Successful kill
				kill(idComponent, SIGTERM);
				std::cout<<"Successfully killed thread with PID number "<<idComponent<<std::endl;
			}else{
				//An error occured during kill function
				std::cout<<"An error occured during kill function"<<std::endl;
			}

		}
}


//No real way to do reset function through deathManager code, each component needs to have its own restart function that the deathManager can access.
void deathManager::reset(pid_t idComponent){}
deathManager::~deathManager(){
	std::cout << "stop test deathManager" << std::endl;
}
}
