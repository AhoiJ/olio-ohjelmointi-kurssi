#pragma once
#include <iostream>
#include <string>

using std::string;

class Oppilas
{
public:
	Oppilas();
	Oppilas(string num_, string enim_, string snim_, string email_);
	~Oppilas();

	// getters
	string annaNum();
	string annaNim();
	string annaSnim();
	string annaEmail();
	
	// setters
	void asetaNum(string num);
	void asetaNim(string enim);
	void asetaSnim(string snim);
	void asetaEmail(string email);

	void tulosta();

private:

	string num_;
	string enim_;
	string snim_;
	string email_;

};

