#include "Koulu.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <conio.h>

using std::cout; using std::cin; using std::getline; using std::endl; using std::ofstream; using std::ifstream; using std::ios;

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

void Koulu::lueTiedotFilesta() const
{

}
