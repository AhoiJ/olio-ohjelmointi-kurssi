#include "Koulutusohjelma.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using std::cout; using std::cin; using std::getline; using std::endl; using std::ofstream; using std::ifstream;

Koulutusohjelma::Koulutusohjelma() : nimi_(), opettajat_(), opiskelijat_()
{
}

Koulutusohjelma::Koulutusohjelma(string nimi) : nimi_(nimi), opettajat_(), opiskelijat_()
{

}


Koulutusohjelma::~Koulutusohjelma()
{
}

void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja tmp;
	tmp.kysyTiedot();
	opettajat_.push_back(tmp); // lis‰t‰‰n vektoriin opettaja
}

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija tmp;
	tmp.kysyTiedot();
	opiskelijat_.push_back(tmp);
	
	string temporary;

}

int Koulutusohjelma::etsiOpettaja()
{
	string nimi;

	cout << " Anna opettajan tunnus: ";
	getline(cin, nimi);

	for (int i = 0; i < opettajat_.size(); i++)
	{
		if (nimi == opettajat_[i].annaTunnus())
			return i;
	}
	return -1;
}

int Koulutusohjelma::etsiOpiskelija()
{
	return -1;
}

void Koulutusohjelma::poistaOpe()
{
	int indeksi = etsiOpettaja();

	if (indeksi > 0)
	{
	opettajat_.erase(opettajat_.begin() + indeksi);
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulutusohjelma::poistaOpiskelijaNumerolla()
{
}

void Koulutusohjelma::tulostaOpettajat() const
{
	for (unsigned int i = 0; i < opettajat_.size(); i++)
		opettajat_[i].tulosta();
}

void Koulutusohjelma::tulostaOpiskelijat() const
{
	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
		opiskelijat_[i].tulosta();
}



string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}
