#include "Calender.h"
// #include "Date.h"
// #include "Clock.h"
#include <iostream>

using std::cout; using std::endl; using std::cin;

Calender::Calender(): date_(), time_(), thing_(""), reminder_(false)
{
}

Calender::Calender(Date day, Clock time, string thing, bool reminder):
	date_(day), time_(time), thing_(thing), reminder_(reminder)
{
}

Calender::Calender(const Calender & original):
	date_(original.date_), time_(original.time_), thing_(original.thing_), reminder_(original.reminder_)
{
}

Calender::~Calender()
{
}

Date Calender::getDay() const
{
	return date_;
}

Clock Calender::getTime() const
{
	return time_;
}

string Calender::getThing() const
{
	return thing_;
}

bool Calender::getReminder() const
{
	return reminder_;
}

void Calender::setDay(Date day)
{
	date_.setDate(day.getDate());
	date_.setMonth(day.getMonth());
	date_.setYear(day.getYear());
}

void Calender::setClock(Clock time)
{
	time_.setTime(time.getHH(), time.getMM(), time.getSS());
}

void Calender::setThing(string thing)
{
	thing_ = thing; // string-luokkaan toteutettu sijoitus operaatio.
}

void Calender::setReminder(bool reminder)
{
	reminder_ = reminder;
}

void Calender::printEntry() const
{
	cout << "-------------------------" << endl;
	date_.print();
	time_.print();
	cout << thing_ << endl;
	if (reminder_)
		cout << "Reminder on " << endl;
	else
		cout << "No reminder" << endl;
	cout << "-------------------------" << endl;
}

void Calender::askInfo()
{
	string minder; //apumuutuja
	date_.askInfo();
	time_.getInfo();
	cin.clear();
	
	cout << endl << "	Enter thing you want to be reminded of:  ";
	getline(cin, thing_);
	
	cout << "	Reminder y / n : ";
	getline(cin, minder);
	
	if (minder == "y" || minder == "Y")
		reminder_ = true;
	else
		reminder_ = false;


}
