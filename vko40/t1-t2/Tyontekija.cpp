#include "Tyontekija.h"
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::getline;


Tyontekija::Tyontekija(): Henkilo(), tunnus_(), palkka_(0.0)
{
}

Tyontekija::Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string tunnus, float palkka) : 
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

void Tyontekija::tulosta() const
{
	Henkilo::tulosta();
	cout << tunnus_ << " " << palkka_ << " ";
}

void Tyontekija::kysyTiedot()
{
	string palkka; // apumuuttuja

	Henkilo::kysyTiedot();
	cout << "	Anna tunnus: ";
	getline(cin, tunnus_);
	cout << "	Anna palkka: ";
	getline(cin, palkka);
	palkka_ = atof(palkka.c_str());

}
