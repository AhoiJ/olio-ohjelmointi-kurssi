#pragma once
#include "Kappale.h"
class Kuutio :
	public Kappale
{
public:
	Kuutio();
	Kuutio(double sarma);
	Kuutio(const Kuutio & alkup);
	~Kuutio();


	// Getters
	double annaSarma();

	// Setters
	void asetaSarma(double sarma);

	double tilavuus();


private:

	double sarma_;

};

