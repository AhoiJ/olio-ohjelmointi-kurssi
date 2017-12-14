#include "Sylinteri.h"
#include <iostream>
#include <cmath>

using namespace std; using std::atan;

Sylinteri::Sylinteri()
{
}

Sylinteri::Sylinteri(double korkeus, double sade): korkeus_(korkeus), sade_(sade)
{
}

Sylinteri::Sylinteri(const Sylinteri & alkup): korkeus_(alkup.korkeus_), sade_(alkup.sade_)
{
}


Sylinteri::~Sylinteri()
{
}

double Sylinteri::annaKorkeus()
{
	return korkeus_;
}

double Sylinteri::annaSade()
{
	return sade_;
}

void Sylinteri::asetaKorkeus(double korkeus)
{
	korkeus_ = korkeus;
}

void Sylinteri::asetaSade(double sade)
{
	sade_ = sade;
}

double Sylinteri::tilavuus()
{
	double temp;
	temp = 4 * atan(1.0) * sade_ * sade_ * korkeus_;

	return temp;
}
