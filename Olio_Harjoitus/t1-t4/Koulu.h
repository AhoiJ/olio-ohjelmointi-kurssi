#pragma once
#include "Koulutusohjelma.h"
#include <string>
#include <vector>

using std::string; using std::vector;

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
	void poistaOpettaja();
	void paivitaOpettaja();

	void lisaaKoulutusohjelmaanOpiskelija();
	void tulostaKoulutusohjelmanOppilaat() const;
	void poistaOppilas();
	void paivitaOppilas();

	void tallennaOpettajat();
	void tallennaOppilaat();

	int noudaKoulutusohjelmienOpettajienMaara(int& indeksi);
	int noudaKoulutusohjelmienOpiskelijoidenMaara(int& indeksi);

	int etsiKoulutusohjelma() const;

	void poistaKoulutusOhjelma();
	void paivitaKoulutusOhjelma();

	void lataaTiedosto();

private:

	string nimi_;
	vector <Koulutusohjelma> koulutusohjelmat_;
	int etsiKoulutusohjelmaLataus(string nimi); // Koulutusohjelman  etsin, ilman kysymistä


};

