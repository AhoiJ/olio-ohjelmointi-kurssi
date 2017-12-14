#include "Kuutio.h"



Kuutio::Kuutio()
{
}

Kuutio::Kuutio(double sarma): sarma_(sarma)
{
}

Kuutio::Kuutio(const Kuutio & alkup): sarma_(alkup.sarma_)
{
}


Kuutio::~Kuutio()
{
}

double Kuutio::annaSarma()
{
	return sarma_;
}

void Kuutio::asetaSarma(double sarma)
{
	sarma_ = sarma;
}

double Kuutio::tilavuus()
{
	return sarma_*sarma_*sarma_;
}
