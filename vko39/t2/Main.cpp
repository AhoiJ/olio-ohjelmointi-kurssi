#include <iostream>
#include <Windows.h>
#include "Clock.h"

using std::cout; using std::endl;

int main()
{
	Clock wallClock;
	Clock rolex(13, 20, 43);
	
	Clock works(rolex);

	wallClock.print();

	rolex.addSecond();
	rolex.print();

	works.print();

	system("pause");
	return 0;
}
