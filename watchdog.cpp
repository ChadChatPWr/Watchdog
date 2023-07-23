#include <iostream>
#include "watchdog.h"

struct mosquitto* watchdog_ = nullptr;
const char* SERVER_ADDRESS = "localhost"; 
const int SERVER_PORT = 1883;

void parseJsonMessage(const std::string& jsonMessage, std::string& idComponent, std::string& componentName){

	if (!(jsonMessage.size() > 1 && jsonMessage.front() == '{' && jsonMessage.back() == '}')) {
        std::cerr << "Error: The message is not valid JSON." << std::endl;
        return;
    }

    size_t idComponentPos = jsonMessage.find("\"idComponent\"");
    size_t componentNamePos = jsonMessage.find("\"componentName\"");

    if (idComponentPos == std::string::npos || componentNamePos == std::string::npos) {
        std::cerr << "Error: The JSON message does not contain 'idComponent' and/or 'componentName' fields." << std::endl;
        return;
    }

	
    idComponentPos = jsonMessage.find("\"", idComponentPos + 13);
    size_t idComponentEndPos = jsonMessage.find("\"", idComponentPos + 1);
    idComponent = jsonMessage.substr(idComponentPos + 1, idComponentEndPos - idComponentPos - 1);

    componentNamePos = jsonMessage.find("\"", componentNamePos + 15);
    size_t componentNameEndPos = jsonMessage.find("\"", componentNamePos + 1);
    componentName = jsonMessage.substr(componentNamePos + 1, componentNameEndPos - componentNamePos - 1);
}

watchdog::watchdog()
{
	mosquitto_lib_init();
    watchdog_ = mosquitto_new(nullptr, true, this);
        if (!watchdog_) {
            std::cerr << "Error: Failed to create MQTT client." << std::endl;
        }
}

void watchdog::connect() {
    if (watchdog_) {
        mosquitto_connect_async(watchdog_, SERVER_ADDRESS, SERVER_PORT, 60);
        mosquitto_subscribe(watchdog_, nullptr, "watchdog", 0);
    }
}

void watchdog::loop() {
    if (watchdog_) {
        mosquitto_loop_start(watchdog_);
    }
}

void watchdog::monitorComponent(struct mosquitto* watchdog_, void* obj, const struct mosquitto_message* message) {
    if (message->payload && message->topic && strcmp(message->topic, "watchdog") == 0) {    
        std::string payload = static_cast<const char*>(message->payload);
        createComponent(payload);
    }
}


void watchdog::createComponent(std::string jsonMessage){
	
	parseJsonMessage(jsonMessage, idComponent, componentName);
	component component(idComponent, componentName);
}


/*
void watchdog::createComponent(const std::vector<std::string>& messages){
	int numObjects = static_cast<int>(messages.size());
    if (numObjects == 0) {
        std::cerr << "Error: No messages received." << std::endl;
        return;
    }

    std::vector<std::thread> threads;
    for (int i = 0; i < numObjects; ++i) {
        std::string idComponent;
        std::string componentName;

        parseJsonMessage(messages[i], idComponent, componentName);

        if (idComponent.empty() || componentName.empty()) {
            std::cerr << "Error: Message " << i << " is missing 'idComponent' and/or 'componentName' fields." << std::endl;
            continue;
        }

        threads.emplace_back([i, idComponent, componentName]() {
            component component(idComponent, componentName);
        });
    }

    for (std::thread& t : threads) {
        t.join();
    }
}
*/


void watchdog::createLifeMonitor(std::string idComponent){}


watchdog::~watchdog()
{
	 if (watchdog_) {
            mosquitto_destroy(watchdog_);
            mosquitto_lib_cleanup();
        }
}


component::component(std::string idComponent, std::string componentName){
	std::cout << "start test component:" << componentName << std::endl << "with ID = " << idComponent << std::endl;
}
void component::runComponentTimer(){}
void component::resetComponentTimer(){}
component::~component(){
	std::cout << "stop test component" << std::endl;
}


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

lifeMonitor::lifeMonitor(){
	std::cout << "start test lifeMonitor" << std::endl;
}
void lifeMonitor::checkStatus(std::string idComponent){}
void lifeMonitor::runWatchdogTimer(std::string idComponent){}
void lifeMonitor::resetWatchdogTimer(std::string idComponent,std::string componentStatus){}
void lifeMonitor::startDeathManager(std::string idComponent){}
lifeMonitor::~lifeMonitor(){
	std::cout << "stop test lifeMonitor" << std::endl;
}
