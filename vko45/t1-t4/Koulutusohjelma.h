#pragma once
#include <string>
#include <vector>
#include "Opiskelija.h"
#include "Opettaja.h"

using std::string; using std::vector;

class Koulutusohjelma
{
public:
	Koulutusohjelma();
	Koulutusohjelma(string nimi);
	~Koulutusohjelma();


	void lisaaOpettaja();
	void lisaaOpiskelija();

	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;


	string annaNimi() const;
	void asetaNimi(string nimi);

private:

	string nimi_;

	vector <Opiskelija> opiskelijat_;
	vector <Opettaja> opettajat_;

};

