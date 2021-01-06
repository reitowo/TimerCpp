#include "timercpp.h"
#include <iostream>

Timer::~Timer()
{
	//We should never leave the sleepy thread alone.
	stop();
}

void Timer::stop()
{
	//Stop the thread from sleep state
	sleepyThread.interrupt();
	//Wait for exit
	if (sleepyThread.joinable())
	{
		try
		{
			sleepyThread.join();
		}
		catch (std::exception)
		{
			std::cerr << "[TimerCpp] Fatal exception when stopping(join) the worker thread." << std::endl;
			abort();
		}
	}
}
