#include <iostream>
#include <Windows.h>
#include "Clock.h"

using std::cout; using std::endl;

int main()
{
	Clock wallClock;
	Clock rolex(13,20,43);
	
	wallClock.print();
	rolex.print();

	system("pause");
	return 0;
}
