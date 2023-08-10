# pragma once
#include <iostream>

namespace watchdog{

class deathManager
{

public:
    deathManager(pid_t idComponent);
	~deathManager();

private:
    void handleUnresponsive(pid_t idComponent);
    void kill(pid_t idComponent);
    void checkIsKIlled(pid_t idComponent);
    void reset(std::string componentName);
};
}
