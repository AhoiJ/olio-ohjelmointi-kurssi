#include <iostream>
#include "Date.h"

using std::endl; using std::cout;

Date::Date() : day_(1), month_(1), year_(1970)
{
	// cout << "Date: default builder " << this << endl;
}

Date::Date(int day, int month, int year) : day_(day), month_(month), year_(year)
{
	// cout << "Date: parameter builder" << this << endl;
}

Date::~Date()
{
	// cout << "Date: demolisher " << this << endl;
	// system("pause");
}

int Date::getDate()
{
	return day_;
}

int Date::getMonth()
{
	return month_;
}

int Date::getYear()
{
	return year_;
}

void Date::setDate(int day)
{
	day_ = day;
}

void Date::setMonth(int month)
{
	month_ = month;
}

void Date::setYear(int year)
{
	year_ = year;
}

void Date::print()
{
	cout << day_ << "." << month_ << "." << year_ << endl;
}

void Date::addDay()
{
}

int Date::howManyDaysInMonth()
{
	if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)
		return 31;
	else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)
		return 30;
	else if ((year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0)
			return 29;
		else
			return 28;
}
