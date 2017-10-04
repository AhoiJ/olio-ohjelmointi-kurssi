#pragma once
class Clock
{
public:

	Clock(); // default builder
	Clock(int hh, int mm, int ss); // parameter builder.
	Clock(const Clock & original);
	~Clock(); // demolisher.

			  // Getters
	int getHH() const;
	int getMM() const;
	int getSS() const;

	// Setters
	void setHH(int hh);
	void setMM(int mm);
	void setSS(int ss);

	void getInfo();
	void setTime(int hh, int mm, int ss);
	void print() const;
	void addSecond();

private:
	int hh_;
	int mm_;
	int ss_;
};

