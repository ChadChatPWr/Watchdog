# pragma once
#include <iostream>

namespace watchdog{

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
}