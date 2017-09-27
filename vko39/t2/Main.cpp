#include <iostream>
#include <Windows.h>
#include "Clock.h"

using std::cout; using std::endl;

int main()
{
	Clock* C1_ptr = new Clock;

	Clock* C2_ptr = new Clock(10, 12, 30);

	Clock* C3_ptr = new Clock(*C2_ptr);

	if (C1_ptr)
	{
		C1_ptr->print();
		delete C1_ptr;
		C1_ptr = 0;
	}

	if (C2_ptr)
	{
		C2_ptr->print();
		delete C2_ptr;
		C2_ptr = 0;
	}

	if (C3_ptr)
	{
		C3_ptr->print();
		delete C3_ptr;
		C3_ptr = 0;
	}

	system("pause");
	return 0;
}
