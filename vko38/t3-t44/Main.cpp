#include "Oppilas.h"
#include "Opettaja.h"
#include <iostream>

using std::cout; using std::endl; using std::cin;

int main()
{
	int choice = 0;
	cout << "	If you want to test student object press 1, for Teacher press 2: " << endl;
	cin >> choice;

	if (choice == 1)
	{
		Oppilas ossi;
		Oppilas oona("1234", "Oona", "Opiskelija", "oona@koulu.fi");

		ossi.tulosta();
		oona.tulosta();

		ossi.asetaEmail("ossi@koulu.fi");
		ossi.asetaNim("Ossi");
		ossi.asetaNum("4321");

		ossi.tulosta();
	}
	if (choice == 2)
	{
		Opettaja ope;
		
		ope.asetaTunnus("Tunnus123");
		ope.asetaEnim("Popettaja");
		ope.asetaSnim("Opettaja");
		ope.asetaPalkka(400.57);

		ope.tulosta();
	}
	system("pause");






}