#include <iostream>
#include <chrono>

#include "watchdog.h"
#include "component.h"
#include "deathManager.h"
#include "lifeMonitor.h"



int main()
{
	watchdog::watchdog watchdog;
	


    std::cout << "id of main thread is:" << std::this_thread::get_id() << std::endl;

    watchdog.monitorComponent();

    std::string s = "WebApp";
    std::string l = "1";

    watchdog.setidComponent(l);
    watchdog.setcomponentName(s);

    watchdog.createComponent(watchdog.getidComponent(),watchdog.getcomponentName());

	return 0;
}
