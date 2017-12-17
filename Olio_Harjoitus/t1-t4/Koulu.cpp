#include "Koulu.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <conio.h>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cout; using std::cin; using std::getline; using std::endl;
using std::ofstream; using std::ifstream; using std::ios; using std::vector;

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

		try
		{
			for (int i = 0; i < 2; i++)
				nimi.at(i);
		}
		catch (std::out_of_range &ex)
		{
			cout << " Vaadin sisaltoa!" << endl;
			return lisaaKoulutusohjelma();
		}

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

	for (unsigned int j = 0; j < koulutusohjelmat_.size(); j++) 
	{
		int apu = j;
		unsigned int apu2 = noudaKoulutusohjelmienOpiskelijoidenMaara(apu); 
		for (unsigned int i = 0; i < apu2; i++) 
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

void Koulu::lataaTiedosto()
{
	string tmp_nimi = " ", nimi, etunimi, sukunimi, opiskelijanumero, osoite, tunnus, opetusala, puhelinnumero, tmp_palkka;
	float palkka; 
	std::string::size_type sz; // String -> Double muunnosta varten.
	int indeksi = 0; // Laskureita ja apumuuttujia 
	int laskuri = -1;
	int laskuri2 = 0;
	int apu = -1;
	int tmp_laskuri = 0;

	ifstream luku_tied_op; // luodaan tiedosto-olio lukua varten

	luku_tied_op.open("Opiskelija.csv");
	if (luku_tied_op.is_open())
	{
		while (luku_tied_op.peek() != EOF) // luetaan tiedosto loppuu, End Of File
		{
			getline(luku_tied_op, nimi, ';'); // Luetaan nimi 
			if (nimi != tmp_nimi) // Tarkistetaan onko nimi uusi
			{
				tmp_nimi = nimi; // Tehdään uudesta nimestä vertailunimi
				koulutusohjelmat_.push_back(nimi);
				indeksi = 0;
				laskuri++;
			}
			getline(luku_tied_op, etunimi, ';');
			getline(luku_tied_op, sukunimi, ';');
			getline(luku_tied_op, osoite, ';');
			getline(luku_tied_op, opiskelijanumero, ';');
			getline(luku_tied_op, puhelinnumero, '\n'); // Käsitellään tiedostoa, ei lueta vielä vektoriin.
			laskuri2++; // Lasketaan montako riviä tiedostossa oli.

		}
		luku_tied_op.close();

		laskuri = -1; // Alustetaan apumuuttujat alkuarvoihin.
		indeksi = 0;
		tmp_nimi = " ";
		nimi = " ";

		luku_tied_op.open("Opiskelija.csv");
		if (luku_tied_op.is_open())
		{
			while (laskuri2 != 0) 
			{
				getline(luku_tied_op, nimi, ';'); // Haetaan nimi
				apu = etsiKoulutusohjelmaLataus(nimi); // Katsotaan nimen sijainti vektorissa.
				getline(luku_tied_op, etunimi, ';'); // Haetaan muut opiskelijan tiedot.
				getline(luku_tied_op, sukunimi, ';');
				getline(luku_tied_op, osoite, ';');
				getline(luku_tied_op, opiskelijanumero, ';');
				getline(luku_tied_op, puhelinnumero, ';');


				if (apu >= 0) 
				{
					tmp_laskuri = apu; 
					koulutusohjelmat_.at(tmp_laskuri).lataaOpiskelija(indeksi, etunimi, sukunimi, osoite, opiskelijanumero, puhelinnumero);
					laskuri2--; // Ensin lisätään opiskelijat vektoriin, sitten vähennetän laskuria, koska rivi käsitelty.
				}
				else // Ei löydy. Lisätään siis opiskelija vektorin seuraavaan vapaaseen paikkaan. 
				{
					laskuri++;
					koulutusohjelmat_.at(laskuri).lataaOpiskelija(indeksi, etunimi, sukunimi, osoite, opiskelijanumero, puhelinnumero);
					laskuri2--;
				}
				apu = -1; // Palautetaan vektorisijainti -1, jotta ei tapahdu virheellistä indeksointia.
			}

			luku_tied_op.close();
		}
		else // Tiedosto käytössä. Ei voida avata.
			cout << "Tiedostoa ei voitu avata! " << endl;
	}
	indeksi = 0;
	laskuri = -1;
	laskuri2 = 0;

	// Palautetaan muuttujat alkuarvoihin opettajien latausta varten.

	luku_tied_op.open("Opettaja.csv"); // Avataan opettajien tiedosto
	if (luku_tied_op.is_open()) // Avaus onnistui
	{
		while (luku_tied_op.peek() != EOF) // luetaan tiedosto loppuu, End Of File
		{
			getline(luku_tied_op, nimi, ';'); // Haetaan koulutusohjelma
			if (nimi != tmp_nimi) // Uusi nimi
			{
				if (etsiKoulutusohjelmaLataus(nimi) >= 0) // Tarkistetaan löytyykö koulutusohjelma jo vektorista.
				{
					// Löytyi. Ei lisätä sitä vektoriin.
				}
				else // Ei löytynyt. Lisätään koulutusohjelma vektoriin ja tehdään lisätystä nimestä uusi vertailunimi.
				{
					tmp_nimi = nimi;
					koulutusohjelmat_.push_back(nimi);
					indeksi = 0;
					laskuri++;
				}
			}
			getline(luku_tied_op, etunimi, ';');
			getline(luku_tied_op, sukunimi, ';');
			getline(luku_tied_op, osoite, ';');
			getline(luku_tied_op, tunnus, ';');
			getline(luku_tied_op, tmp_palkka, ';'); // TÄSSÄ PALKKA ON STRING
			getline(luku_tied_op, opetusala, ';');
			getline(luku_tied_op, puhelinnumero, '\n'); 
			laskuri2++; 

		}

		luku_tied_op.close();

		laskuri = -1;
		indeksi = 0;
		tmp_nimi = " ";
		apu = -1;

		luku_tied_op.open("Opettaja.csv"); // Avataan tiedosto uudelleen opettajien latausta varten.
		if (luku_tied_op.is_open())
		{
			while (laskuri2 != 0) // luetaan tiedosto loppuu, End Of File
			{
				getline(luku_tied_op, nimi, ';');
				apu = etsiKoulutusohjelmaLataus(nimi); // Etsitään koulutusohjelman sijainti vektorista.
				getline(luku_tied_op, etunimi, ';');
				getline(luku_tied_op, sukunimi, ';');
				getline(luku_tied_op, osoite, ';');
				getline(luku_tied_op, tunnus, ';');
				getline(luku_tied_op, tmp_palkka, ';'); // Otetaan palkka apumuuttujalla string muodossa.
				palkka = std::stof(tmp_palkka, &sz); // Muunnetaan palkka stringistä doubleksi.
				getline(luku_tied_op, opetusala, ';');
				getline(luku_tied_op, puhelinnumero, ';');


				if (apu >= 0) // Koulutusohjelma löytyi vektorista.
				{
					tmp_laskuri = apu; // Lisätään opettaja olio oikeaan vektorin paikkaan. Lisäys aliohjelmassa lataaOpettaja.
					koulutusohjelmat_.at(tmp_laskuri).lataaOpettaja(indeksi, etunimi, sukunimi, osoite, tunnus, palkka, opetusala, puhelinnumero);
					laskuri2--;
				}
				else
				{
					laskuri++; // Lisätään laskuria. Lisätään opettaja olio oikeaan paikkaan. Lisäys aliohjelmassa.
					koulutusohjelmat_.at(laskuri).lataaOpettaja(indeksi, etunimi, sukunimi, osoite, tunnus, palkka, opetusala, puhelinnumero);
					laskuri2--;
				}

			}

			luku_tied_op.close();
			cout << "Rekisterin lataus onnistui" << endl;
		}
		else
			cout << "Tiedostoa ei voitu avata! " << endl; // Ei voitu avata tiedostoa.
	}

}

int Koulu::etsiKoulutusohjelmaLataus(string nimi)
{
	string ko_nimi; // Apumuuttuja

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) // Käydään kaikki koulutusohjelmat läpi.
	{
		ko_nimi = koulutusohjelmat_.at(i).annaNimi();

		std::transform(ko_nimi.begin(), ko_nimi.end(), ko_nimi.begin(), ::tolower);
		std::transform(nimi.begin(), nimi.end(), nimi.begin(), ::tolower);

		if (nimi == ko_nimi) // Nimi löytyi.
		{
			return i;
		}
	}

	return -1; // Nimeä ei löytynyt.

}


