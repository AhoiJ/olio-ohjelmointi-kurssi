#include "Opettaja.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::getline; using std::ofstream;


Opettaja::Opettaja() : Tyontekija(), opetusala_()
{
}

Opettaja::Opettaja(string etunimi, string sukunimi, string osoite, string tunnus, float palkka, string puhelinnumero, string opetusala) :
	Tyontekija(etunimi, sukunimi, osoite, tunnus, palkka, puhelinnumero), opetusala_(opetusala)
{
}

Opettaja::Opettaja(const Opettaja & alkup) : Tyontekija(alkup), opetusala_(alkup.opetusala_)
{
}


Opettaja::~Opettaja()
{
}

string Opettaja::annaOpetusala() const
{
	return opetusala_;
}

void Opettaja::asetaOpetusala(string opetusala)
{
	opetusala_ = opetusala;
}



Opettaja & Opettaja::operator=(const Opettaja & alkup)
{
	if (this != &alkup)
	{
		Henkilo::operator=(alkup);

		opetusala_ = alkup.opetusala_;
	}
	return *this;
}

void Opettaja::kysyTiedot()
{
	Tyontekija::kysyTiedot();

	int opeTark = 0;

	do
	{

		cout << "	Anna opetusala: ";
		getline(cin, opetusala_);

		for (int i = 0; i < opetusala_.length(); i++)
		{
			if (isalpha(opetusala_[i]))
				opeTark++;
		}
		if (opeTark == opetusala_.length())
			opeTark = 1;
		else
			opeTark = 0;

		if (opeTark == 0)
		{
			cout << " Syotteessa saa olla vain kirjaimia " << endl;
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}

	} while (opeTark == 0);

}

void Opettaja::tulosta() const
{
	Tyontekija::tulosta();
	cout << opetusala_ << endl;
}
