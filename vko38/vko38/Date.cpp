#include <iostream>
#include "Date.h"

using std::endl; using std::cout;

Date::Date() : day_(1), month_(1), year_(1970)
{
	cout << "Date: default builder " << this << endl;
}

Date::Date(int day, int month, int year) : day_(day), month_(month), year_(year)
{
	cout << "Date: parameter builder" << this << endl;
}

Date::~Date()
{
	cout << "Date: demolisher " << this << endl;
	system("pause");
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