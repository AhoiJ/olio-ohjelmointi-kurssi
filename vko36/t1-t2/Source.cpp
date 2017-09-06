#include <iostream>
#include "Date.h"

int main()
{
	Date today;
	today.setDate(6);
	today.setMonth(9);
	today.setYear(2017);

	today.print();

	system("pause");
	return 0;
}