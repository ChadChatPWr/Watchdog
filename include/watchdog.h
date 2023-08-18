# pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <atomic>

#include "component.h"

namespace watchdog{
	
    class watchdog
{
public:

    watchdog();
    void setidComponent(pid_t idComponent);
    pid_t getidComponent();
    void setcomponentName(std::string componentName);
    std::string getcomponentName();
    static void createComponent(const pid_t& idComponent,const std::string& componentName, std::atomic<bool>& shouldClose );
    void monitorComponent();
    ~watchdog();

private:

    pid_t idComponent;
    std::string componentName;

};
}
