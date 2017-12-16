#include "Tyontekija.h"
#include <iostream>
#include <conio.h>

using std::cout; using std::cin; using std::endl; using std::getline;


Tyontekija::Tyontekija() : Henkilo(), tunnus_(), palkka_(0.0)
{
}

Tyontekija::Tyontekija(string etunimi, string sukunimi, string osoite, string tunnus, float palkka, string puhelinnumero) :
	Henkilo(etunimi, sukunimi, osoite, puhelinnumero), tunnus_(tunnus), palkka_(palkka)
{
}

Tyontekija::Tyontekija(const Tyontekija & alkup) : Henkilo(alkup), tunnus_(alkup.tunnus_), palkka_(alkup.palkka_)
{
}


Tyontekija::~Tyontekija()
{
}

string Tyontekija::annaTunnus() const
{
	return tunnus_;
}

float Tyontekija::annaPalkka() const
{
	return palkka_;
}

void Tyontekija::asetaTunnus(string tunnus)
{
	tunnus_ = tunnus;
}

void Tyontekija::asetaPalkka(float palkka)
{
	palkka_ = palkka;
}


Tyontekija & Tyontekija::operator=(const Tyontekija & alkup)
{
	if (this != &alkup)
	{
		Henkilo::operator=(alkup);

		tunnus_ = alkup.tunnus_;

		palkka_ = alkup.palkka_;
	}
	return *this;
}

void Tyontekija::tulosta() const
{
	Henkilo::tulosta();
	cout << tunnus_ << " " << palkka_ << " ";
}

void Tyontekija::kysyTiedot()
{
	string palkka; // apumuuttuja

	Henkilo::kysyTiedot();

	int tunnusTark = 0;
	int palkkaTark = 0;

	do
	{
		cout << "	Anna tunnus: ";
		getline(cin, tunnus_);

		for (int i = 0; i < tunnus_.length(); i++)
		{
			if (isdigit(tunnus_[i]))
				tunnusTark++;
		}
		if (tunnusTark == tunnus_.length())
			tunnusTark = 1;
		else
			tunnusTark = 0;
		
		if (tunnusTark == 0)
		{
			cout << " Syotteessa saa olla vain numeroja " << endl;
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}
	} while (tunnusTark == 0);

	do
	{

		cout << "	Anna palkka: ";
		getline(cin, palkka);


		for (int i = 0; i < palkka.length(); i++)
		{
			if (isdigit(palkka[i]))
				palkkaTark++;
		}
		if (palkkaTark == palkka.length())
			palkkaTark = 1;
		else
			palkkaTark = 0;

		if (palkkaTark == 0)
		{
			cout << " Syotteessa saa olla vain numeroja " << endl;
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}

	} while (palkkaTark == 0);

	palkka_ = atof(palkka.c_str());
}
