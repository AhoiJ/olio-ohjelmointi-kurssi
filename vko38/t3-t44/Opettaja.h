#pragma once
#include <string>
#include <iostream>
using std::string;


class Opettaja
{
public:
	Opettaja();
	Opettaja(string tunnus, string enim, string snim, float palkka);
	~Opettaja();
	// getters
	string annaTunnus();
	string annaEnim();
	string annaSnim();
	float annaPalkka();

	// setters
	void asetaTunnus(string tunnus);
	void asetaEnim(string enim);
	void asetaSnim(string snim);
	void asetaPalkka(float palkka);

	void tulosta();

	private:
		string tunnus_;
		string enim_;
		string snim_;
		float palkka_;
};

