#include <iostream>
#include "watchdog.h"

int main()
{
	watchdog watchdog;

	watchdog.watchdog::connect();
	watchdog.watchdog::loop();

	return 0;
}