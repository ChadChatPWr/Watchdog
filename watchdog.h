# pragma once
#include <string>
#include <thread>
#include <vector>

class watchdog
{
public:
	std::string idComponent;
	std::string componentName;

	watchdog();
	~watchdog();
	void monitorComponent();

private:

	void createComponent(const std::vector<std::string>& messages);
	//void createComponent(std::string jsonMessage);
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

	std::string checkStatus(std::string idComponent);
	void runWatchdogTimer(std::string idComponent);
	void resetWatchdogTimer(std::string idComponent,std::string componentStatus);
	void startDeathManager(std::string idComponent);
};
