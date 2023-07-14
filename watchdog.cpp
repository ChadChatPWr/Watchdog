#include <iostream>
#include "watchdog.h"


watchdog::watchdog()
{
	std::cout << "konstruktor" << std::endl;
}
watchdog::~watchdog()
{
	std::cout << "destruktor" << std::endl;
}

