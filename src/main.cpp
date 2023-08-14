#include <iostream>
#include <cstdlib>

#include "watchdog.h"
#include "component.h"
#include "deathManager.h"
#include "lifeMonitor.h"


bool shouldCreateNewTask = true;


int main()
{
    watchdog::watchdog watchdog;
    watchdog.monitorComponent();
	
    std::atomic<bool> shouldClose;
    shouldClose = false;



    std::cout << "id of main thread is:" << std::this_thread::get_id() << std::endl;

    if(shouldCreateNewTask){ //later will be if(recive())

    std::string s = "WebApp";
    pid_t l = 1;

    watchdog.setidComponent(l);
    watchdog.setcomponentName(s);

    watchdog.createComponent(watchdog.getidComponent(),watchdog.getcomponentName() ,shouldClose);
}


	return 0;
}
