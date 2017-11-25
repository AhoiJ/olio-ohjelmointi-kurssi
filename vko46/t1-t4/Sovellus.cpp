#include "Sovellus.h"
#include <windows.h>
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

	Koulutusohjelma ahoi;

	string valinta;

	ofstream file;

	file.open("Tiedot.csv");

	do
	{
		system("cls");
		valinta = tulostaValikko();

		if (valinta == "1")
			testi.lisaaKoulutusohjelma();

		else if (valinta == "2")
		{
			testi.tulostaKoulutusohjelma();
			Sleep(2500);						// Sleep asetettuna jotta system("cls") ei clearaisi valinnan tulosta niin nopeasti,
												// my�hemmin tarvitsee paremman ratkaisun kun tulostetta on enemm�n.
		}
		else if (valinta == "3")
		{
			testi.tulostaKoulutusohjelmienMaara();
			Sleep(2500);
		}
		else if (valinta == "4")
			testi.lisaaKoulutusohjelmaanOpettaja();

		else if (valinta == "5")
		{
			testi.tulostaKoulutusohjelmanOpettajat();
			Sleep(2500);
		}
		else if (valinta == "6")
			testi.lisaaKoulutusohjelmaanOpiskelija();

		else if (valinta == "7")
		{
			testi.tulostaKoulutusohjelmanOppilaat();
			Sleep(2500);
		}
		else if (valinta == "14")
			testi.lueTiedotFilesta();

		else if (valinta == "0")
			cout << endl;

		else {
			cout << endl << "Virheellinen sy�te!";
			Sleep(2500);
		}

	} while (valinta != "0");

}

string Sovellus::tulostaValikko() const
{
	string valinta;

	cout << endl << "__________________________________";
	cout << endl << "1) Lis�� koulutusohjelma";
	cout << endl << "2) Tulosta koulutusohjelmien nimet";
	cout << endl << "3) Tulosta koulutusohjelmien m��r�";
	cout << endl << "4) Lis�� koulutusohjelmaan opettaja";
	cout << endl << "5) Tulosta koulutusohjelman opettajat";
	cout << endl << "6) Lis�� koulutusohjelmaan opiskelija";
	cout << endl << "7) Tulosta koulutusohjelman opiskelijat";
//	cout << endl << "8) Poista koulutusohjelma";
//	cout << endl << "9) Poista opettaja";
//	cout << endl << "10) Poista opiskelija";
//	cout << endl << "11) P�ivit� koulutusohjelman nimi";
//	cout << endl << "12) P�ivit� opettajan tiedot";
//	cout << endl << "13) P�ivit� opiskelijan tiedot";
	cout << endl << "14) Lue tiedot";
//	cout << endl << "15) Tallenna tiedot";
	cout << endl << "0) Lopeta";

	cout << endl << "Valintasi: ";
	getline(cin, valinta);

	return valinta;
}
