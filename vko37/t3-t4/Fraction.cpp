#include "Fraction.h"
#include <iostream>

using std::cout; using std::endl; using std::cin;

Fraction::Fraction() :os_(1), nim_(1)
{
}

Fraction::Fraction(int os, int nim): os_(os), nim_(nim)
{
}


Fraction::~Fraction()
{
}

int Fraction::getOs()
{
	return os_;
}

int Fraction::getNim()
{
	return nim_;
}

void Fraction::setOs(int os)
{
	os_ = os;
}

void Fraction::setNim(int nim)
{
	nim_ = nim;
}

void Fraction::print()
{
	cout << os_ << "/" << nim_ << endl;
}

void Fraction::askInfo()
{
	cout << "Anna osoittaja: ";
	cin >> os_;
	cout << "Anna nimittaja";
	cin >> nim_;
}

void Fraction::keke()
{
}
