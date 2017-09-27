#include "Calender.h"



Calender::Calender(): day_(), time_(), thing_(""), reminder_(false)
{
}

Calender::Calender(Date day, Clock time, string thing, bool reminder):
	day_(day), time_(time), thing_(thing), reminder_(reminder)
{
}

Calender::Calender(const Calender & original)
{
}


Calender::~Calender()
{
}

Date Calender::getDay() const
{
	return Date();
}

Clock Calender::getTime() const
{
	return Clock();
}

string Calender::getThing() const
{
	return string();
}

bool Calender::getReminder() const
{
	return false;
}

void Calender::setDay(Date day)
{
}

void Calender::setClock(Clock time)
{
}

void Calender::setThing(string thing)
{
}

void Calender::setReminder(bool reminder)
{
}

void Calender::printEntry() const
{
}

void Calender::askInfo()
{
}
