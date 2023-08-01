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
    void setidComponent(std::string idComponent);
    std::string getidComponent();
    void setcomponentName(std::string componentName);
    std::string getcomponentName();
    static void createComponent(const std::string& idComponent,const std::string& componentName, std::atomic<bool>& shouldClose );
    void monitorComponent();
    ~watchdog();

private:

    std::string idComponent;
    std::string componentName;

};
}
