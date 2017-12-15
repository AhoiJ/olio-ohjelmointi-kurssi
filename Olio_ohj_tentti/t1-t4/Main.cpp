#include "Kappale.h"
#include "Sylinteri.h"
#include "Kuutio.h"
#include <iostream>

using std::cout; using std::endl;


int main()
{
	// TEHTÄVÄ 3

	Sylinteri obj(5.0, 4.2);

	Kuutio kapp(4.7);

	cout << "Sylinterin tilavuus: " << obj.tilavuus() << endl;

	cout << "Kuution tilavuus: " << kapp.tilavuus() << endl;

	system("pause");
	return 0;
	

	// tehtävä 4

	Sylinteri obj(5.0, 4.2);

	Kuutio* u =	new Kuutio (2.5);

	Kuutio kopiokapp = *u;

	Kappale *osoitin = &kopiokapp;

	Kappale *tokaOsoitin = &obj;

	cout << "Kuutio: " << osoitin->tilavuus() << endl;

	cout << "Sylinteri: " << tokaOsoitin->tilavuus() << endl;

	system("pause");
	return 0;
}