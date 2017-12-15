#include "Sovellus.h"
#include <windows.h>
#include <conio.h>
#include <fstream>

using std::cout; using std::cin; using std::getline; using std::endl; using std::ofstream;

Sovellus::Sovellus()
{
	
}


Sovellus::~Sovellus()
{
}


void Sovellus::aja() const
{
	Koulu testi("TAMK"); // pakko luoda parametrirakentaja, defaultrakentaja ei toimi koska siin� ei ole asetettu parametrej�.

//	Koulutusohjelma ahoi;

	string valinta;

	ofstream file;

	file.open("Tiedot.csv");

	do
	{
		system("cls");
		valinta = tulostaValikko();

		if (valinta == "1")
		{
			testi.lisaaKoulutusohjelma();
			do {
				cout << "Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);

		}

		else if (valinta == "2")
		{
			testi.tulostaKoulutusohjelma();
			do {
				cout << "Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);

		}

		else if (valinta == "3")
		{
			testi.tulostaKoulutusohjelmienMaara();
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		
		}

		else if (valinta == "4")
		{
			testi.lisaaKoulutusohjelmaanOpettaja();
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}
		else if (valinta == "5")
		{
			testi.tulostaKoulutusohjelmanOpettajat();
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}

		else if (valinta == "6")
		{
			testi.lisaaKoulutusohjelmaanOpiskelija(); // Opiskelijatiedot lis�t��n cvs fileen opiskelija.cpp:ss�, t�ytyy tehd� erillinen toiminto?
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}
		else if (valinta == "7")
		{
			testi.tulostaKoulutusohjelmanOppilaat();
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}
		
		else if (valinta == "8")
		{
			testi.poistaKoulutusOhjelma(); // t��l� nyt

			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);

		}

		else if (valinta == "9")
		{
			testi.poistaOpettaja();

			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);

		}

		else if (valinta == "10")
		{
			testi.poistaOppilas();

			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);

		}

		/*	else if (valinta == "14")
			{
				testi.lueTiedotFilesta(); // poistettu kaikki tallennus ja lukemis koodit
				Sleep(2500);
			}

			else if(valinta == "15")
			{

			}
		*/
		else if (valinta == "0")
		{
			cout << " Haluatko varmasti lopettaa? syota y " << endl;
			int painallus = _getch();
			if (painallus == 89 || painallus == 121)
				valinta = "0";
			else
				valinta = "127";
		}

		else {
			cout << endl << "Virheellinen sy�te!";
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
		}

	} while (valinta != "0");

}

string Sovellus::tulostaValikko() const
{
	string valinta;

	int paatos = 0;
	do
	{

		cout << endl << "__________________________________";
		cout << endl << "1) Lisaa koulutusohjelma";
		cout << endl << "2) Tulosta koulutusohjelmien nimet";
		cout << endl << "3) Tulosta koulutusohjelmien maara";
		cout << endl << "4) Lisaa koulutusohjelmaan opettaja";
		cout << endl << "5) Tulosta koulutusohjelman opettajat";
		cout << endl << "6) Lisaa koulutusohjelmaan opiskelija";
		cout << endl << "7) Tulosta koulutusohjelman opiskelijat";
		cout << endl << "8) Poista koulutusohjelma";
		cout << endl << "9) Poista opettaja";
		cout << endl << "10) Poista opiskelija";
		//	cout << endl << "11) P�ivit� koulutusohjelman nimi";
		//	cout << endl << "12) P�ivit� opettajan tiedot";
		//	cout << endl << "13) P�ivit� opiskelijan tiedot";
		//	cout << endl << "14) Lue tiedot";
		//	cout << endl << "15) Tallenna tiedot";
		cout << endl << "0) Lopeta";

		cout << endl << "Valintasi: ";
		getline(cin, valinta);
		
		for (int i = 0; i < valinta.length(); i++)
		{
			if (isdigit(valinta[i]))
				paatos = 1;
		}
		if (paatos == 0)
		{
			cout << " Syota numero! " << endl;
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
			system("cls");
		}
	} while (paatos == 0);

	return valinta;
}