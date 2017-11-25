#include "Opiskelija.h"
#include <iostream>
#include <fstream>

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


Opiskelija & Opiskelija::operator=(const Opiskelija & alkup)
{
	if (this != &alkup)
	{
		Henkilo::operator=(alkup);

		opiskelijanumero_ = alkup.opiskelijanumero_;
	}
	return *this;
}

void Opiskelija::asetaTiedotFileen() const
{
	ofstream file;

	file.open("Oppilastiedot.csv");
	file << Opiskelija::annaEtunimi();
	file << ";";
	file << Opiskelija::annaSukunimi();
	file << ";";
	file << Opiskelija::annaOsoite();
	file << ";";
	file << Opiskelija::annaPuhelinnumero();
	file << ";";
	file << Opiskelija::annaOpiskelijanumero();
	file << ";";
	file.close();
}


void Opiskelija::kysyTiedot()
{
	Henkilo::kysyTiedot();
	cout << "	Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero_);

}

void Opiskelija::tulosta() const
{
	Henkilo::tulosta();
	cout << opiskelijanumero_ << endl;
}
