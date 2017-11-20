#include <iostream>
#include "Header.h"

heady::heady() : intti1_(1), intti2_(2), intti3_(3)
{
}

heady::heady(int intti1, int intti2, int intti3) : intti1_(intti1), intti2_(intti2), intti3_(intti3)
{
}

heady::~heady()
{
}

void heady::asetaInt1(int intti1)
{
	intti1_ = intti1;
}

void heady::asetaInt2(int intti2)
{
	intti2_ = intti2;
}

void heady::asetaInt3(int intti3)
{
	intti3_ = intti3;
}

int heady::annaInt1() const
{
	return intti1_;
}

int heady::annaInt2() const
{
	return intti2_;
}

int heady::annaInt3() const
{
	return intti3_;
}

void heady::laitaVektoriin()
{
	vektori_.push_back(intti1_);
	vektori_.push_back(intti2_);
	vektori_.push_back(intti3_);
	
	try 
	{
		vektori_.at(8) = 30;
	}
	catch (const std::out_of_range& oor) {
		
		cout << "Out of Range error: " << oor.what() << endl;
	}

	for (int i = 0; i < 3; i++)
		cout << vektori_[i] << endl;

	/*try
	{



	}
	catch
	{



	}
	*/

}
