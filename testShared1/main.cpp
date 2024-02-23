#include <iostream>
import ObjectClass;
import TimeClass;

//#include <chrono>
int main()
{
	////////////////////////////////////////////////////////////////////////////
	///스톱워치
	//time_class::CreateStopWatch(L"TestStopWatch");
	//auto testStopWatch = time_class::GetStopWatch(L"TestStopWatch").lock();
	//testStopWatch->Start();
	//while (true)
	//{
	//	std::cout << testStopWatch->GetDuration_toYears().count() << std::endl;
	//	std::cout << testStopWatch->GetDuration_toMonths().count() << std::endl;
	//	std::cout << testStopWatch->GetDuration_toWeeks().count() << std::endl;
	//	std::cout << testStopWatch->GetDuration_toDay().count() << std::endl;
	//	std::cout << testStopWatch->GetDuration_toHours().count() << std::endl;
	//	std::cout << testStopWatch->GetDuration_toMinutes().count() << std::endl;
	//	std::cout << testStopWatch->GetDuration_toSeconds().count() << std::endl;
	//	std::cout << testStopWatch->GetDuration_toMilliseconds().count() << std::endl;
	//	system("cls");
	//}

	////////////////////////////////////////////////////////////////////////////
	///카운터
	//time_class::CreateIntervalCounter(L"TestIntervalCounter");
	//auto testIntervalCounter = time_class::GetIntervalCounter(L"TestIntervalCounter").lock();
	//testIntervalCounter->Start(1000);
	//int lastNum = 0;
	//while (true)
	//{
	//	auto current = testIntervalCounter->Counter();
	//	if (lastNum != current)
	//	{
	//		lastNum = current;
	//		std::cout << current << std::endl;
	//	}
	//}

	////////////////////////////////////////////////////////////////////////////
	///타이머
	//time_class::CreateTimer(L"TestTimer");
	//auto testTimer = time_class::GetTimer(L"TestTimer").lock();
	//testTimer->Start(2000);
	//int lastNum = 0;
	//while (true)
	//{
	//	if (testTimer->IsOver() == true)
	//	{
	//		testTimer->Start(2000);
	//		std::cout << "2초경과" << std::endl;
	//	}
	//}




	exit(0);
}