#include "Opettaja.h"
#include "Henkilo.h"
#include <iostream>



int main()
{
	Opettaja o1;
	Opettaja o2("ope", "Opettaja", "katu 223", "3355112", "opeo", 3200, "koodaus");
	Opettaja o3(o2);

	o1.tulosta();
	o1.kysyTiedot();
	o1.tulosta();

	o2.tulosta();
	o3.tulosta();

	system("pause");
	return 0;
}