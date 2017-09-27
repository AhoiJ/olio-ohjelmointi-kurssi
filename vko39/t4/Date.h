
#pragma once
class Date
{
public:
	Date(); // default builder
	Date(int day, int month, int year); // parameter builder
	Date(const Date& original); // Copybuilder
	~Date(); // demolisher?

			 // getters
	int getDate() const;
	int getMonth() const;
	int getYear() const;

	//setters
	void setDate(int day);
	void setMonth(int month);
	void setYear(int year);

	void print() const;

	void addDay();
	int howManyDaysInMonth() const;

private:
	int day_;
	int month_;
	int year_;
};

