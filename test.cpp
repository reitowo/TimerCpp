#include "timercpp.h"
#include <thread>
#include <iostream>

void scopedTimerTest1()
{
	Timer scopedTimer;
	scopedTimer.setTimeout([=]()
	{
		std::cout << "- Scoped Timeout" << std::endl;
	}, 1000); 
}

void scopedTimerTest2()
{
	Timer scopedTimer;
	scopedTimer.setInterval([=]()
	{
		static int cnt = 0;
		++cnt;
		std::cout << "- Count " << cnt << std::endl;
	}, 1000);

	std::this_thread::sleep_for(std::chrono::seconds(4));
}

int main()
{
	Timer timer;

	//Test 1: setInterval, should print 1 - 10
	std::cout << "setInterval start: should print 1 - 10" << std::endl; 
	timer.setInterval([=]()
	{
		static int cnt = 0;
		++cnt;
		std::cout << "- Count " << cnt << std::endl;
	}, 1000);

	std::this_thread::sleep_for(std::chrono::seconds(11));

	//Test 2: stop
	std::cout << "setInterval stop" << std::endl;
	timer.stop();

	//Test 3: stop the stopped timer
	std::cout << "setInterval stop again" << std::endl;
	timer.stop();

	//Test 4: setTimeout, should print Timeout after 1 sec 
	std::cout << "setTimeout start: should print once" << std::endl;
	timer.setTimeout([=]()
	{
		std::cout << "- Timeout" << std::endl;
	}, 1000);

	std::this_thread::sleep_for(std::chrono::seconds(2));

	//Test 5: stop the stopped timer
	std::cout << "setTimeout stop again" << std::endl;
	timer.stop();

	//Test 6: will the setTimeout stop after we leave an scope? Should print nothing
	std::cout << "scopedTimerTest1 start: should print nothing" << std::endl;
	scopedTimerTest1(); 
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "scopedTimerTest1 end" << std::endl;

	//Test 7: will the setInterval stop after we leave an scope? Should print 1 - 3
	std::cout << "scopedTimerTest2 start: should print 1 - 3" << std::endl;
	scopedTimerTest2();
	std::cout << "scopedTimerTest2 end" << std::endl;

	std::this_thread::sleep_until(std::chrono::system_clock::time_point::max());
}
