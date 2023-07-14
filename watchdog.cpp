#include <iostream>
#include "watchdog.h"

class watchdog
{
	public:
	watchdog()
	{
		std::cout<<"konstruktor"<<std::endl;
	}
	~watchdog()
	{
		std::cout<<"destruktor"<<std::endl;
	}
};

