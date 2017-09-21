#include <iostream>
#include "Date.h"

using std::cout; using std::endl;

int main()
{
	// Date Today; // With default builder
	// Today.print();

	 Date Tomorrow(21, 2, 2016); // with paramter builder
	 Tomorrow.print();
	

	if (Tomorrow.howManyDaysInMonth() == 29)
		cout << endl << "Days: " << Tomorrow.howManyDaysInMonth() << " This year is leap year." << endl;
	else
		cout << endl << "Days: " << Tomorrow.howManyDaysInMonth() << " This year is not a leap year." << endl;
	system("pause");
	return 0;
}