#include <iostream>
#include "Date.h"

using std::endl; using std::cout; using std::cin;

Date::Date() : day_(1), month_(1), year_(1970)
{
	// cout << "Date: default builder " << this << endl;
}

Date::Date(int day, int month, int year) : day_(day), month_(month), year_(year)
{
	// cout << "Date: parameter builder" << this << endl;
}

Date::Date(const Date & original): day_(original.day_), month_(original.month_), year_(original.year_)
{
//	cout << "Copybuilder" << endl;
}

Date::~Date()
{
	// cout << "Date: demolisher " << this << endl;
	// system("pause");
}

int Date::getDate() const
{
	return day_;
}

int Date::getMonth() const
{
	return month_;
}

int Date::getYear() const
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

void Date::print() const
{
	cout << day_ << "." << month_ << "." << year_ << endl;
}

void Date::askInfo()
{
	cout << endl << "	Enter day: ";
	cin >> day_;
	cin.ignore();
	cout << endl << "	Enter month: ";
	cin >> month_;
	cin.ignore();
	cout << endl << "	Enter year: ";
	cin >> year_; 
	cin.ignore();

}

void Date::addDay()
{
	int dayAmount = howManyDaysInMonth();
	if (day_ < dayAmount)
		day_++;
	else
	{
		day_ = 1; //month changes
		month_++;
		if (month_ > 12)
		{
			month_ = 1; // year changes
			year_++;
		}
	}

}

int Date::howManyDaysInMonth() const
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
