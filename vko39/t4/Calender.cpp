#include "Calender.h"
#include "Date.h"
#include "Clock.h"
#include <iostream>

using std::cout; using std::endl;

Calender::Calender(): day_(), time_(), thing_(""), reminder_(false)
{
}

Calender::Calender(Date day, Clock time, string thing, bool reminder):
	day_(day), time_(time), thing_(thing), reminder_(reminder)
{
}

Calender::Calender(const Calender & original):
	day_(original.day_), time_(original.time_), thing_(original.thing_), reminder_(original.reminder_)
{
}

Calender::~Calender()
{
}

Date Calender::getDay() const
{
	return day_;
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
	day_.setDate(day.getDate());
	day_.setMonth(day.getMonth());
	day_.setYear(day.getYear());
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
	cout << " You have a reminder for " << &day_.setDate << "." << &day_.setMonth << &day_.setYear << "juu kesken";
}

void Calender::askInfo()
{
}
