#include <iostream>
#include "Date.h"

using std::endl; using std::cout;

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