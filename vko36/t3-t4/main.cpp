#include <iostream>
#include <Windows.h>
#include "Clock.h"

using std::cout; using std::endl;

int main()
{
	Clock wallClock;
	wallClock.setTime(10, 59, 59);
	while (true)
	{
		wallClock.print();
		wallClock.addSecond();
	//	Sleep(998);
	}
	system("pause");
	return 0;
}