#include <iostream>
#include "Date.h"
#include <Windows.h>

using std::cout; using std::endl;

int main()
{
	// Date Today; // With default builder
	// Today.print();

	 Date Tomorrow(21, 2, 2016); // with paramter builder
	
	 for (;;)
	 {
		 Tomorrow.print();
		 Tomorrow.addDay();
		 Sleep(200);
		
	 }


	if (Tomorrow.howManyDaysInMonth() == 29)
		cout << endl << "Days: " << Tomorrow.howManyDaysInMonth() << endl;
	else
		cout << endl << "Days: " << Tomorrow.howManyDaysInMonth() << endl;
	system("pause");
	return 0;
}