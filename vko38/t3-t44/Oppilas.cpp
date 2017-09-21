#include "Oppilas.h"
#include <iostream>

using std::cout; using std::endl;

Oppilas::Oppilas()
{
}

Oppilas::Oppilas(string num, string enim, string snim, string email):
	num_(num), enim_(enim), snim_(snim), email_(email)
{
}


Oppilas::~Oppilas()
{
}

string Oppilas::annaNum()
{
	return num_;
}

string Oppilas::annaNim()
{
	return enim_;
}

string Oppilas::annaSnim()
{
	return snim_;
}

string Oppilas::annaEmail()
{
	return email_;
}

void Oppilas::asetaNum(string num)
{
	num_ = num;
}

void Oppilas::asetaNim(string nim)
{
	enim_ = nim;
}

void Oppilas::asetaSnim(string snim)
{
	snim_ = snim;
}

void Oppilas::asetaEmail(string email)
{
	email_ = email;
}

void Oppilas::tulosta()
{
	cout << num_ << " " << enim_ << " " << snim_ << " " << email_ << endl;
}
