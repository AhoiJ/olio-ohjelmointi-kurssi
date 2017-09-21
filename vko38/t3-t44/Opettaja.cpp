#include "Opettaja.h"



Opettaja::Opettaja(): palkka_(0.0) // string - luokka alustaa muut
{
}

Opettaja::Opettaja(string tunnus, string enim, string snim, float palkka) :
	tunnus_(tunnus), enim_(enim), snim_(snim), palkka_(palkka)
{
}


Opettaja::~Opettaja()
{
}

string Opettaja::annaTunnus()
{
	return tunnus_;
}

string Opettaja::annaEnim()
{
	return enim_;
}

string Opettaja::annaSnim()
{
	return snim_;
}

float Opettaja::annaPalkka()
{
	return 0.0f;
}

void Opettaja::asetaTunnus(string tunnus)
{
	tunnus_ = tunnus;
}

void Opettaja::asetaEnim(string enim)
{
	enim_ = enim;
}

void Opettaja::asetaSnim(string snim)
{
	snim_ = snim;
}

void Opettaja::asetaPalkka(float palkka)
{
	palkka_ = palkka;
}

void Opettaja::tulosta()
{
	cout << tunnus_ << " " << enim_ << " " << " " << snim_ << " " << palkka_ << endl;
}
