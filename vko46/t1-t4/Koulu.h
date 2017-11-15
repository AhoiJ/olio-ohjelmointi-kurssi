#pragma once
#include "Koulutusohjelma.h"


using std::string;

class Koulu
{
public:
	Koulu();
	Koulu(string nimi);
	~Koulu();

	string annaNimi() const;
	void asetanimi(string nimi);
	void lisaaKoulutusohjelma();
	void tulostaKoulutusohjelma() const;
	void tulostaKoulutusohjelmienMaara() const;

	void lisaaKoulutusohjelmaanOpettaja();
	void tulostaKoulutusohjelmanOpettajat() const;

	void lisaaKoulutusohjelmaanOpiskelija();
	void tulostaKoulutusohjelmanOppilaat() const;

	int etsiKoulutusohjelma() const;

private:

	string nimi_;
	vector <Koulutusohjelma> koulutusohjelmat_;

};

