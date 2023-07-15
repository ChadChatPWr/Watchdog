# pragma once
#include <string>

class watchdog
{
public:
	std::string idComponent;

	watchdog();
	~watchdog();

private:
	void monitorComponent();
	void createComponent(std::string idComponent);
	void createLifeMonitor(std::string idComponent);
};

class component
{
public:
	std::string componentStatus;

	component();
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
