#include "Koulutusohjelma.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using std::cout; using std::cin; using std::getline; using std::endl; using std::ofstream; using std::ifstream;

Koulutusohjelma::Koulutusohjelma() : nimi_(), opettajat_(), opiskelijat_()
{
}

Koulutusohjelma::Koulutusohjelma(string nimi) : nimi_(nimi), opettajat_(), opiskelijat_()
{

}


Koulutusohjelma::~Koulutusohjelma()
{
}

void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja tmp;
	tmp.kysyTiedot();
	opettajat_.push_back(tmp); // lis‰t‰‰n vektoriin opettaja
}

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija tmp;
	tmp.kysyTiedot();
	opiskelijat_.push_back(tmp);
	
	string temporary;


	ofstream file;

	file.open("Opiskelijatiedot.csv");
	file << Koulutusohjelma::annaNimi();
	file << ";";

	std::ostream_iterator<Opiskelija> output_iterator(file, "\n");
	std::copy(opiskelijat_.begin(), opiskelijat_.end(), output_iterator);

	file.close();








//	tmp.asetaTiedotFileen();	// opiskelija.cpp:ss‰ on funktio joka lis‰‰ tiedot cvs fileen



}

void Koulutusohjelma::tulostaOpettajat() const
{
	for (unsigned int i = 0; i < opettajat_.size(); i++)
		opettajat_[i].tulosta();
}

void Koulutusohjelma::tulostaOpiskelijat() const
{
	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
		opiskelijat_[i].tulosta();
}



string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}
