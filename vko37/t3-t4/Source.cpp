#include "Fraction.h"
#include <iostream>

int main()
{
	Fraction ml;
	ml.print();
	ml.askInfo();
	ml.print();

	Fraction ml2(3,9);
	ml2.print();

	system("pause");
	return 0;

}