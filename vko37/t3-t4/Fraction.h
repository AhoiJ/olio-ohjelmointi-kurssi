#pragma once
class Fraction
{
public:
	Fraction();
	Fraction(int os, int nim);
	~Fraction();

	// getters
	int getOs();
	int getNim();

	//setters
	void setOs(int os);
	void setNim(int nim);

	void print();
	void askInfo();

private:

	int os_;
	int nim_;

};

