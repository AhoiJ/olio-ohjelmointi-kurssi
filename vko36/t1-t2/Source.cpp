#include <iostream>
#include "Date.h"

using std::cout; using std::endl;

int main()
{
	Date today;
	today.setDate(6);
	today.setMonth(9);
	today.setYear(2017);

	cout << today.getDate() << "/" << today.getMonth() << "/" << today.getYear() << endl;

	today.print();

	system("pause");
	return 0;
}