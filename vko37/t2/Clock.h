#pragma once
class Clock
{
public:

	Clock(); // default builder
	Clock(int hh, int mm, int ss); // parameter builder.
	~Clock(); // demolisher.

	// Getters
	int getHH();
	int getMM();
	int getSS();

	// Setters
	void setHH(int hh);
	void setMM(int mm);
	void setSS(int ss);

	void setTime(int hh, int mm, int ss);
	void print();
	void addSecond();

private:
	int hh_;
	int mm_;
	int ss_;
};

