#pragma once
#include "Henkilo.h"
class Tyontekija :
	public Henkilo
{
public:
	Tyontekija();
	Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string tunnus, float palkka);
	Tyontekija(const Tyontekija & alkup);
	~Tyontekija();
	//getters
	string annaTunnus() const;
	float annaPalkka() const;
	//setters
	void asetaTunnus(string tunnus);
	void asetaPalkka(float palkka);

	void tulosta() const;
	void kysyTiedot();


private:
	string tunnus_;
	float palkka_;
};

