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

	void lueTiedotFilesta() const;

private:

	string nimi_;
	vector <Koulutusohjelma> koulutusohjelmat_;

};

