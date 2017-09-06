#pragma once
class Date
{
public:
	// getters
	int getDate();
	int getMonth();
	int getYear();
	
	//setters
	void setDate(int day);
	void setMonth(int month);
	void setYear(int year);

	void print();

private:
	int day_;
	int month_;
	int year_;
};