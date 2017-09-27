#pragma once
#include "Date.h"
#include "Clock.h"
#include <string>

using std::string;

class Calender
{
public:
	Calender();
	Calender(Date day, Clock time, string thing, bool reminder);
	Calender(const Calender& original);
	~Calender();

	Date getDay() const;
	Clock getTime() const;
	string getThing() const;
	bool getReminder() const;

	void setDay(Date day);
	void setClock(Clock time);
	void setThing(string thing);
	void setReminder(bool reminder);

	void printEntry() const;
	void askInfo();

private:

	Date day_;
	Clock time_;
	string thing_;
	bool reminder_;
};

