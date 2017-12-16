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
	Koulu testi("TAMK"); // pakko luoda parametrirakentaja, defaultrakentaja ei toimi koska siinä ei ole asetettu parametrejä.

	string valinta;

//	ofstream opeFile;
//	ofstream oppilasFile;

//	opeFile.open("Opettaja.csv");
//	oppilasFile.open("Opiskelija.csv");

	do
	{
		system("cls");
		valinta = tulostaValikko();

		if (valinta == "1")
		{
			testi.lisaaKoulutusohjelma();
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);

		}

		else if (valinta == "2")
		{
			testi.tulostaKoulutusohjelma();
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

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
			testi.lisaaKoulutusohjelmaanOpiskelija();
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
			testi.poistaKoulutusOhjelma(); 

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

		else if (valinta == "11")
		{
			testi.paivitaKoulutusOhjelma();

			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);

		}

		else if (valinta == "12")
		{
			testi.paivitaOpettaja();

			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);

		}

		else if (valinta == "13")
		{
			testi.paivitaOppilas();

			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);

		}

			else if (valinta == "14")
			{
				testi.lataaTiedosto(); 
				
				do {
					cout << " Paina valilyontia jatkaaksesi " << endl;

				} while (_getch() != 32);
			}
			
			else if(valinta == "15")
			{
				cout << " Tietojen tallennus " << endl;

				testi.tallennaOpettajat();
				testi.tallennaOppilaat();

				do {
					cout << " Paina valilyontia jatkaaksesi " << endl;

				} while (_getch() != 32);

			}
		
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
			cout << endl << "Virheellinen syöte!";
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
		cout << endl << "11) Paivita koulutusohjelman nimi";
		cout << endl << "12) Paivita opettajan tiedot";
		cout << endl << "13) Paivita opiskelijan tiedot";
		cout << endl << "14) Lue tiedot";
		cout << endl << "15) Tallenna tiedot";
		cout << endl << "0) Lopeta";

		cout << endl << "Valintasi: ";
		getline(cin, valinta);
		
		for (int i = 0; i < valinta.length(); i++)
		{
			if (isdigit(valinta[i]))
				paatos++;
		}
		if (paatos == valinta.length())
			paatos = 1;
		else
			paatos = 0;

		if (paatos == 0)
		{
			cout << " Syota vain numeroita! " << endl;
			do {
				cout << " Paina valilyontia jatkaaksesi " << endl;

			} while (_getch() != 32);
			system("cls");
		}
	} while (paatos == 0);

	return valinta;
}
