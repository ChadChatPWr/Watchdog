# pragma once
#include <iostream>
#include <string>
#include <thread>

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
    void monitorComponent();
    void createComponent(std::string idComponent,std::string componentName);
    ~watchdog();

private:

    std::string idComponent;
    std::string componentName;

};
}
