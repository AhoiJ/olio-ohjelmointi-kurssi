#include "Calender.h"
#include "Clock.h"
#include "Date.h"
#include <iostream>
#include <string>

using std::cout; using std::endl;

int main()
{
	Calender Paiva(Date(21,2,2016),Clock(8, 45, 28), "holotaa", true);
	Calender Paiva2;
	Calender Paiva3(Paiva);

	Paiva2.askInfo();
	Paiva2.printEntry();

	Paiva.printEntry();
	Paiva3.printEntry();


	system("pause");
	return 0;


}