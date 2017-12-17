#include "Henkilo.h"
#include <conio.h>
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::getline;



Henkilo::Henkilo() : etunimi_(), sukunimi_(), osoite_(), puhelinnumero_()
{
}

Henkilo::Henkilo(string etunimi, string sukunimi, string osoite, string puhelinnumero)
	: etunimi_(etunimi), sukunimi_(sukunimi), osoite_(osoite), puhelinnumero_(puhelinnumero)
{
}

Henkilo::Henkilo(const Henkilo & alkup)
	: etunimi_(alkup.etunimi_), sukunimi_(alkup.sukunimi_), osoite_(alkup.osoite_), puhelinnumero_(alkup.puhelinnumero_)
{
}


Henkilo::~Henkilo()
{
}

string Henkilo::annaEtunimi() const
{
	return etunimi_;
}

string Henkilo::annaSukunimi() const
{
	return sukunimi_;
}

string Henkilo::annaOsoite() const
{
	return osoite_;
}

string Henkilo::annaPuhelinnumero() const
{
	return puhelinnumero_;
}

void Henkilo::asetaEtunimi(string etunimi)
{
	etunimi_ = etunimi;
}

void Henkilo::asetaSukunimi(string sukunimi)
{
	sukunimi_ = sukunimi;
}

void Henkilo::asetaOsoite(string osoite)
{
	osoite_ = osoite;
}

void Henkilo::asetaPuhelinnumero(string puhelinnumero)
{
	puhelinnumero_ = puhelinnumero;
}

/*
Henkilo & Henkilo::operator=(const Henkilo & alkup)
{
	if (this != &alkup)
	{ // Jos ei sijoiteta itseen
		etunimi_ = ""; // Vapauta vanha.
		etunimi_ = alkup.etunimi_;
		sukunimi_ = "";		// Tätä ei tarvitse tehdä string: tyypeille.
		sukunimi_ = alkup.sukunimi_;
		osoite_ = "";		// String hoitaa sen itse.
		osoite_ = alkup.osoite_;
		puhelinnumero_ = "";
		puhelinnumero_ = alkup.puhelinnumero_;
	}
	return *this;
}
*/

void Henkilo::kysyTiedot()
{
	int enimTark = 0;
	int snimTark = 0;
	int puhnumTark = 0;

	do
	{

			cout << "	Anna etunimi: ";
			getline(cin, etunimi_);
		
			try
			{
				for (int i = 0; i < 2; i++)
					etunimi_.at(i);
			}
			catch (std::out_of_range &ex)
			{
				cout << " Vaadin sisaltoa!" << endl;
				return kysyTiedot();
			}
		
			for (int i = 0; i < etunimi_.length(); i++)
			{
				if (isalpha(etunimi_[i]))
					enimTark++;
			}
	
		if (enimTark == etunimi_.length())
			enimTark = 1;
		else
			enimTark = 0;

		if (enimTark == 0)
		{
			cout << " Syotteessa saa olla vain kirjaimia " << endl;
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}
	} while (enimTark == 0);

	do
	{
		cout << "	Anna sukunimi: ";
		getline(cin, sukunimi_);

		for (int i = 0; i < sukunimi_.length(); i++)
		{
				if (isalpha(sukunimi_[i]))
					snimTark++;
			}
		if (snimTark == sukunimi_.length())
			snimTark = 1;
		else
			snimTark = 0;

		if (snimTark == 0)
		{
			cout << " Syotteessa saa olla vain kirjaimia " << endl;
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}

	} while (snimTark == 0);


		cout << "	Anna osoite: ";
		getline(cin, osoite_);

	do
	{
		cout << "	Anna puhelinnumero: ";
		getline(cin, puhelinnumero_);

		for (int i = 0; i < puhelinnumero_.length(); i++)
		{
			if (isdigit(puhelinnumero_[i]))
				puhnumTark++;
		}
		if (puhnumTark == puhelinnumero_.length())
			puhnumTark = 1;
		else
			puhnumTark = 0;

		if (puhnumTark == 0)
		{
			cout << " Syotteessa saa olla vain numeroja " << endl;
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}

	} while (puhnumTark == 0);

}

void Henkilo::tulosta() const
{
	cout << etunimi_ << " " << sukunimi_ << " " << osoite_ << " " << puhelinnumero_ << " ";
}
