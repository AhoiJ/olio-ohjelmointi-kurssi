#include "Koulu.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <conio.h>
#include <iterator>

using std::cout; using std::cin; using std::getline; using std::endl;
using std::ofstream; using std::ifstream; using std::ios;

Koulu::Koulu() : nimi_(), koulutusohjelmat_()
{
}

Koulu::Koulu(string nimi) : nimi_(nimi), koulutusohjelmat_()
{
}


Koulu::~Koulu()
{
}

string Koulu::annaNimi() const
{
	return nimi_;
}

void Koulu::asetanimi(string nimi)
{
	nimi_ = nimi;
}

void Koulu::lisaaKoulutusohjelma()
{
	string nimi;

	int koulOhjTark = 0;

	do
	{
		cout << " Anna uuden koulutusohjelman nimi: ";
		getline(cin, nimi);

		for (int i = 0; i < nimi.length(); i++)
		{
			if (isalpha(nimi[i]))
				koulOhjTark++;
		}

		if (koulOhjTark == nimi.length())
			koulOhjTark = 1;
		else
			koulOhjTark = 0;

		if (koulOhjTark == 0)
		{
			cout << " Syotteessa saa olla vain kirjaimia " << endl;
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}

	} while (koulOhjTark == 0);

	Koulutusohjelma tmp(nimi);

	koulutusohjelmat_.push_back(tmp);
}

void Koulu::tulostaKoulutusohjelma() const
{
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
		cout << koulutusohjelmat_[i].annaNimi() << endl;
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << " Koulutusohjelmien maara: " << koulutusohjelmat_.size() << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].lisaaOpettaja();
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].tulostaOpettajat();
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulu::poistaOpettaja()
{
	cout << " Valitsit Opettajan poiston " << endl;
	
	int	indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].poistaOpe();
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulu::paivitaOpettaja()
{
	cout << " Valitsit Opettajan paivityksen " << endl;

	int	indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].paivitaOpe();
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].lisaaOpiskelija();
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulu::tulostaKoulutusohjelmanOppilaat() const
{
	int indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].tulostaOpiskelijat();
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::poistaOppilas()
{

	cout << " Valitsit Oppilaan poiston " << endl;

	int	indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].poistaOpiskelijaNumerolla();
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;


}

void Koulu::paivitaOppilas()
{
	cout << " Valitsit Oppilaan paivityksen " << endl;

	int	indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].paivitaOppilas();
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulu::tallennaOpettajat()
{

	//	Opettaja tallennus;

	ofstream opeFile;

	opeFile.open("Opettaja.csv");

	string tmp_etunimi, tmp_sukunimi, tmp_opnumero, tmp_osoite, tmp_puhelinnumero, tmp_tunnus, tmp_opetusala;
	float tmpPalkka;
	int indeksi = 0;

	for (unsigned int j = 0; j < koulutusohjelmat_.size(); j++) // Kunnes kaikki koulutusohjelmat on tallennettu.
	{
		int apu = j;
		unsigned int apu2 = noudaKoulutusohjelmienOpettajienMaara(apu);

		for (unsigned int i = 0; i < apu2; i++) // Kirjoitetaan tiedostoa kunnes kaikki koulutusohjelman opiskelijat on tallennettu, sitten seuraavaa koulutusohjelmaa.
		{
			indeksi = i;
			koulutusohjelmat_[j].tallennaOpettaja(indeksi, tmp_etunimi, tmp_sukunimi, tmp_osoite, tmp_tunnus, tmpPalkka, tmp_opetusala, tmp_puhelinnumero);
			opeFile << koulutusohjelmat_[j].annaNimi() << ";" << tmp_etunimi << ";" << tmp_sukunimi << ";" << tmp_osoite << ";" << tmp_tunnus << ";" << tmpPalkka << ";" << tmp_opetusala << ";" << tmp_puhelinnumero << ";" << endl;
		}
	}
	opeFile.close(); // Tiedoston sulkeminen.

}

void Koulu::tallennaOppilaat()
{
	ofstream oppilasFile;

	oppilasFile.open("Opiskelija.csv");


	string tmp_etunimi, tmp_sukunimi, tmp_opnumero, tmp_osoite, tmp_puhelinnumero, tmp_tunnus, tmp_opetusala;
	float tmpPalkka;
	int indeksi = 0;

	for (unsigned int j = 0; j < koulutusohjelmat_.size(); j++) // Kunnes kaikki koulutusohjelmat on tallennettu.
	{
		int apu = j;
		unsigned int apu2 = noudaKoulutusohjelmienOpiskelijoidenMaara(apu); // Apumuuttuja, jotta opiskelijat saadaan kaikki tallennettua
		for (unsigned int i = 0; i < apu2; i++) // Kirjoitetaan tiedostoa kunnes kaikki koulutusohjelman opiskelijat on tallennettu, sitten seuraavaa koulutusohjelmaa.
		{
			indeksi = i;
			koulutusohjelmat_[j].tallennaOpiskelija(indeksi, tmp_etunimi, tmp_sukunimi, tmp_osoite, tmp_opnumero, tmp_puhelinnumero);
			oppilasFile << koulutusohjelmat_[j].annaNimi() << ";" << tmp_etunimi << ";" << tmp_sukunimi << ";" << tmp_osoite << ";" << tmp_opnumero << ";" << tmp_puhelinnumero << ";" << endl;
		}
	}
	oppilasFile.close(); // Tiedoston sulkeminen.

}


int Koulu::noudaKoulutusohjelmienOpettajienMaara(int & indeksi)
{
	int apu;
	apu = koulutusohjelmat_[indeksi].opettajienMaara(indeksi);
	return apu;
}

int Koulu::noudaKoulutusohjelmienOpiskelijoidenMaara(int & indeksi)
{
	int apu;
	apu = koulutusohjelmat_[indeksi].opiskelijoidenMaara(indeksi);
	return apu;
}

//Metodi palauttaa kohdan vektorista, josta koulutusohjelma löytyy. Jos ei löydy, palautuu -1.

int Koulu::etsiKoulutusohjelma() const
{
	string nimi;
	cout << " Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	for (unsigned int i = 0; i<koulutusohjelmat_.size(); i++)
	{
		if (nimi == koulutusohjelmat_.at(i).annaNimi())
		{
			return i;
		}
	}
	return -1; // ei löytynyt, palautetaan -1
}

void Koulu::poistaKoulutusOhjelma()
{
	cout << " Valitsit koulutusohjelman poiston " << endl;

	int indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
	{
		koulutusohjelmat_.erase(koulutusohjelmat_.begin() + indeksi);
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;

}

void Koulu::paivitaKoulutusOhjelma()
{
	cout << " Valitsit koulutusohjelman paivitysen " << endl;

	int indeksi = etsiKoulutusohjelma();

	string testi;

	if (indeksi >= 0)
	{
		cout << " Anna uusi nimi: ";

		getline(cin, testi);

		koulutusohjelmat_[indeksi].asetaNimi(testi);
	}
	else
		cout << " Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::lueTiedotFilesta() const
{

}
