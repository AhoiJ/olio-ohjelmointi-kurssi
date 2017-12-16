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

	int etsiOpettaja();
	int etsiOpiskelija();

	void poistaOpe();
	void paivitaOpe();

	void poistaOpiskelijaNumerolla();
	void paivitaOppilas();
	string tallennaOpettaja(int& indeksi, string& etunimi, string& sukunimi, string& osoite, string& tunnus, float& palkka, string& opetusala, string& puhelinnumero);
	string tallennaOpiskelija(int& indeksi, string& etunimi, string& sukunimi, string& osoite, string& opiskelijanumero, string& puhelinnumero);

	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;

	int opettajienMaara(int& indeksi);
	int opiskelijoidenMaara(int& indeksi);

	string annaNimi() const;
	void asetaNimi(string nimi);

private:

	string nimi_;

	vector <Opiskelija> opiskelijat_;
	vector <Opettaja> opettajat_;

};

