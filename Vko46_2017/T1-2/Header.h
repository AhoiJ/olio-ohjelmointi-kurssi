#pragma once
#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::cin; using std::endl; using std::cout; using std::string; using std::vector;

class heady
{
public:

	heady();
	heady(int intti1, int intti2, int intti3);
	~heady();


	// getters 
	void asetaInt1(int intti1);
	void asetaInt2(int intti2);
	void asetaInt3(int intti3);


	// setters
	int annaInt1() const;
	int annaInt2() const;
	int annaInt3() const;


	void laitaVektoriin();



private:

	int intti1_;
	int intti2_;
	int intti3_;

	vector <int> vektori_;


};