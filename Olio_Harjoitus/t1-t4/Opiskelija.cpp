#include "Opiskelija.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using std::cout; using std::cin; using std::endl; using std::getline; using std::ofstream;


Opiskelija::Opiskelija() : Henkilo(), opiskelijanumero_()
{
}

Opiskelija::Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero) :
	Henkilo(etunimi, sukunimi, osoite, puhelinnumero), opiskelijanumero_(opiskelijanumero)
{
}

Opiskelija::Opiskelija(const Opiskelija & alkup) : Henkilo(alkup), opiskelijanumero_(alkup.opiskelijanumero_)
{
}


Opiskelija::~Opiskelija()
{
}

string Opiskelija::annaOpiskelijanumero() const
{
	return opiskelijanumero_;
}

void Opiskelija::asetaOpiskelijanumero(string opiskelijanumero)
{
	opiskelijanumero_ = opiskelijanumero;
}

/*
Opiskelija & Opiskelija::operator=(const Opiskelija & alkup)
{
	if (this != &alkup)
	{
		Henkilo::operator=(alkup);

		opiskelijanumero_ = alkup.opiskelijanumero_;
	}
	return *this;
}
*/

void Opiskelija::asetaTiedotFileen() const
{
	
}


void Opiskelija::kysyTiedot()
{
	Henkilo::kysyTiedot();

	int opiskelijaNumTark = 0;

	do
	{
		cout << "	Anna opiskelijanumero: ";
		getline(cin, opiskelijanumero_);

		try
		{
			for (int i = 0; i < 5; i++)
				opiskelijanumero_.at(i);
		}
		catch (std::out_of_range &ex)
		{
			cout << " Vahintaan 6 merkkia sisaltoa!" << endl;
			return kysyTiedot();
		}

		for (int i = 0; i < opiskelijanumero_.length(); i++)
		{
			if (isdigit(opiskelijanumero_[i]))
				opiskelijaNumTark++;
		}

		if (opiskelijaNumTark == opiskelijanumero_.length())
			opiskelijaNumTark = 1;
		else
			opiskelijaNumTark = 0;

		if (opiskelijaNumTark == 0)
		{
			cout << " Syotteessa saa olla vain numeroja " << endl;
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}
	} while (opiskelijaNumTark == 0);
}

void Opiskelija::tulosta() const
{
	Henkilo::tulosta();
	cout << opiskelijanumero_ << endl;
}
