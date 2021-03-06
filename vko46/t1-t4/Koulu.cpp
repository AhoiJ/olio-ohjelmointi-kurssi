#include "Koulu.h"
#include <iostream>
#include <fstream>
#include <ios>

using std::cout; using std::cin; using std::getline; using std::endl; using std::ofstream; using std::ifstream; using std::ios;

Koulu::Koulu() : nimi_(), koulutusohjelmat_()
{
}

Koulu::Koulu(string nimi) : nimi_(nimi), koulutusohjelmat_()
{
}


Koulu::~Koulu()
{
}

string Koulu::annaNimi() const
{
	return nimi_;
}

void Koulu::asetanimi(string nimi)
{
	nimi_ = nimi;
}

void Koulu::lisaaKoulutusohjelma()
{
	string nimi;

	cout << "	Anna uuden koulutusohjelman nimi: ";
	getline(cin, nimi);

	Koulutusohjelma tmp(nimi);

	koulutusohjelmat_.push_back(tmp);
}

void Koulu::tulostaKoulutusohjelma() const
{
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
		cout << koulutusohjelmat_[i].annaNimi() << endl;
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << "	Koulutusohjelmien maara: " << koulutusohjelmat_.size() << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].lisaaOpettaja();
	}
	else
		cout << "	Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].tulostaOpettajat();
	}
	else
		cout << "	Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].lisaaOpiskelija();
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::tulostaKoulutusohjelmanOppilaat() const
{
	int indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].tulostaOpiskelijat();
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;
}


//Metodi palauttaa kohdan vektorista, josta koulutusohjelma l�ytyy. Jos ei l�ydy, palautuu -1.

int Koulu::etsiKoulutusohjelma() const
{
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	for (unsigned int i = 0; i<koulutusohjelmat_.size(); i++)
	{
		if (nimi == koulutusohjelmat_.at(i).annaNimi())
		{
			return i;
		}
	}
	return -1; // ei l�ytynyt, palautetaan -1
}

void Koulu::lueTiedotFilesta() const
{

	ifstream file("Oppilastiedot.cvs");
	string value;

	while (file.good())
	{
		getline(file, value, ';'); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
		cout << string(value, 1, value.length() - 2); // display value removing the first and the last character from it
	}

}
