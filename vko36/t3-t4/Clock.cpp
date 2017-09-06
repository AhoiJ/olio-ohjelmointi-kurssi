#include <iostream>
#include "Clock.h"

using std::cout; using std::endl;

int Clock::getHH()
{
	return hh_;
}

int Clock::getMM()
{
	return mm_;
}

int Clock::getSS()
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

void Clock::print()
{
	cout << hh_ << " h " << mm_ << " min " << ss_ << " sec " << endl;
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