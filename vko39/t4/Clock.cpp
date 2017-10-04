
#include <iostream>
#include "Clock.h"

using std::cout; using std::endl; using std::cin;


Clock::Clock() : hh_(0), mm_(0), ss_(0)
{
}

Clock::Clock(int hh, int mm, int ss) : hh_(hh), mm_(mm), ss_(ss)
{
}

Clock::Clock(const Clock & original) : hh_(original.hh_), mm_(original.mm_), ss_(original.ss_)
{
//	cout << " Copybuilder" << endl;
}


Clock::~Clock()
{
//	cout << "Clock demolisher" << endl;
}

int Clock::getHH() const
{
	return hh_;
}

int Clock::getMM() const
{
	return mm_;
}

int Clock::getSS() const
{
	return ss_;
}

void Clock::setHH(int hh)
{
	hh_ = hh;
}

void Clock::setMM(int mm)
{
	mm_ = mm;
}

void Clock::setSS(int ss)
{
	ss_ = ss;
}

void Clock::print() const
{
	cout << hh_ << " h " << mm_ << " min " << ss_ << " sec " << endl;
}

void Clock::getInfo()
{
	cout << endl << "	Enter hours: ";
	cin >> hh_;
	cin.ignore();
	cout << endl << "	Enter minutes: ";
	cin >> mm_;
	cin.ignore();
	cout << endl << "	Enter seconds: ";
	cin >> ss_;
	cin.ignore();

}

void Clock::setTime(int hh, int mm, int ss)
{
	hh_ = hh;
	mm_ = mm;
	ss_ = ss;
}

void Clock::addSecond()
{
	ss_++;
	if (ss_ >= 60)
	{
		mm_++;
		ss_ = 0;

		if (mm_ >= 60)
		{
			hh_++;
			mm_ = 0;

			if (hh_ >= 24)
				hh_ = 0;
		}
	}

}
