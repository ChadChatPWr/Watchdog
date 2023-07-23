# pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "mosquitto.h"
#include <thread>
#include <vector>


class watchdog
{
public:
	std::string idComponent;
	std::string componentName;
	struct mosquitto* watchdog_;

	watchdog();
	~watchdog();
	void connect();
	void loop();
	void monitorComponent(struct mosquitto* watchdog, void* obj, const struct mosquitto_message* message);

private:


	//void createComponent(const std::vector<std::string>& messages);
	void createComponent(std::string jsonMessage);
	void createLifeMonitor(std::string idComponent);
};

class component
{
public:
	std::string componentStatus;

	component(std::string idComponent, std::string componentName);
	~component();

private:
	int componentTimer;

	void runComponentTimer();
	void resetComponentTimer();
};

class deathManager
{

public:
	deathManager();
	~deathManager();

private:
	void handleUnresponsive(std::string idComponent);
	void kill(std::string idComponent);
	void checkIsKIlled(std::string idComponent);
	void reset(std::string idComponent);
};

class lifeMonitor
{

public:
	lifeMonitor();
	~lifeMonitor();

private:
	int watchdogTimer;

	void checkStatus(std::string idComponent);
	void runWatchdogTimer(std::string idComponent);
	void resetWatchdogTimer(std::string idComponent,std::string componentStatus);
	void startDeathManager(std::string idComponent);
};
