# pragma once
#include <string>

class watchdog
{
public:
	watchdog();
	void monitorComponent();
	~watchdog();
};

class component
{
public:
	std::string idComponent;
	std::string componentStatus;
	int componentTimer;

	component();
	void runComponentTimer();
	void resetComponentTimer();
	~component();
};

class watchdogTimer
{

public:
	watchdogTimer(std::string idComponent);
	void resetWatchdogTImer(std::string idComponent,std::string componentStatus);
	~watchdogTimer();
};

class deathManager
{

public:
	deathManager();
	void handleUnresponsive(std::string idComponent);
	void kill(std::string idComponent);
	void checkIsKIlled(std::string idComponent);
	void reset(std::string idComponent);
	~deathManager();
};

class lifeMonitor
{

public:
	lifeMonitor();
	void createComponent(std::string idComponent);
	std::string checkStatus(std::string idComponent);
	void setTimerWatchddog(std::string idComponent);
	void startDeathManager(std::string idComponent);
	~lifeMonitor();
};
