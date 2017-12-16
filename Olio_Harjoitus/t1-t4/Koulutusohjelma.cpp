#include "Koulutusohjelma.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <conio.h>
#include <iterator>

using std::cout; using std::cin; using std::getline; using std::endl;
using std::ofstream; using std::ifstream; using std::ios;


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
	
	// string temporary;

}

int Koulutusohjelma::etsiOpettaja()
{
	string nimi;

	cout << " Anna opettajan tunnus: ";
	getline(cin, nimi);

	for (unsigned int i = 0; i < opettajat_.size(); i++)
	{
		if (nimi == opettajat_[i].annaTunnus())
			return i;
	}
	return -1;
}

int Koulutusohjelma::etsiOpiskelija()
{
	string nimi;

	cout << " Anna opiskelijan opiskelijanumero: ";
	getline(cin, nimi);

	for (int i = 0; i < opiskelijat_.size(); i++)
	{
		if (nimi == opiskelijat_[i].annaOpiskelijanumero())
			return i;
	}
	return -1;
}

void Koulutusohjelma::poistaOpe()
{
	int indeksi = etsiOpettaja();

	if (indeksi >= 0)
	{
		opettajat_.erase(opettajat_.begin() + indeksi);
		
	}
	else
		cout << " Opettajaa ei loytynyt ";
}

void Koulutusohjelma::paivitaOpe()
{
	int indeksi = etsiOpettaja();

	if (indeksi >= 0)
	{
		opettajat_[indeksi].kysyTiedot();
	}
	else
		cout << " Opettajaa ei loytynyt ";
}

void Koulutusohjelma::poistaOpiskelijaNumerolla()
{
	int indeksi = etsiOpiskelija();

	if (indeksi >= 0)
	{
		opiskelijat_.erase(opiskelijat_.begin() + indeksi);
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulutusohjelma::paivitaOppilas()
{
	int indeksi = etsiOpiskelija();

	if (indeksi >= 0)
	{
		opiskelijat_[indeksi].kysyTiedot();
	}
	else
		cout << " Opettajaa ei loytynyt ";

}

string Koulutusohjelma::tallennaOpettaja(int & indeksi, string & etunimi, string & sukunimi, string & osoite, string & tunnus, float & palkka, string & opetusala, string & puhelinnumero)
{
	etunimi = opettajat_.at(indeksi).annaEtunimi();
	sukunimi = opettajat_.at(indeksi).annaSukunimi();
	osoite = opettajat_.at(indeksi).annaOsoite();
	tunnus = opettajat_.at(indeksi).annaTunnus();
	palkka = opettajat_.at(indeksi).annaPalkka();
	opetusala = opettajat_.at(indeksi).annaOpetusala();
	puhelinnumero = opettajat_.at(indeksi).annaPuhelinnumero();

	return indeksi, etunimi, sukunimi, osoite, tunnus, palkka, opetusala, puhelinnumero;
}

string Koulutusohjelma::tallennaOpiskelija(int & indeksi, string & etunimi, string & sukunimi, string & osoite, string & opiskelijanumero, string & puhelinnumero)
{
	
	etunimi = opiskelijat_.at(indeksi).annaEtunimi(); 
	sukunimi = opiskelijat_.at(indeksi).annaSukunimi(); 
	osoite = opiskelijat_.at(indeksi).annaOsoite(); 
	opiskelijanumero = opiskelijat_.at(indeksi).annaOpiskelijanumero();
	puhelinnumero = opiskelijat_.at(indeksi).annaPuhelinnumero();

	return etunimi, sukunimi, osoite, opiskelijanumero, puhelinnumero; 
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

int Koulutusohjelma::opettajienMaara(int & indeksi)
{
	indeksi = opettajat_.size();
	return indeksi;
}

int Koulutusohjelma::opiskelijoidenMaara(int & indeksi)
{
	indeksi = opiskelijat_.size();
	return indeksi;
}



string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}
