#include <iostream>
#include "Date.h"
#include <Windows.h>

using std::cout; using std::endl;

int main()
{
	Date today;
	Date tomorrow(28, 9, 2017);
	Date dayAfter(tomorrow);
	dayAfter.addDay();

	today.print();
	tomorrow.print();
	dayAfter.print();

	system("pause");
	return 0;
}