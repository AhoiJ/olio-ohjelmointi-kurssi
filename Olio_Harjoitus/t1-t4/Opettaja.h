#pragma once
#include "Tyontekija.h"
class Opettaja :
	public Tyontekija
{
public:
	Opettaja();
	Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, string tunnus, float palkka, string opetusala);
	Opettaja(const Opettaja & alkup);
	~Opettaja();
	//getters
	string annaOpetusala() const;
	//setters
	void asetaOpetusala(string opetusala);

	Opettaja& operator =(const Opettaja& alkup);

	void kysyTiedot();
	void tulosta() const;

private:
	string opetusala_;

};

