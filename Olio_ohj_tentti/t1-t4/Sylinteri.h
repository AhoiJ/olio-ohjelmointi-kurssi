#pragma once
#include "Kappale.h"
class Sylinteri :
	public Kappale
{
public:
	Sylinteri();
	Sylinteri(double korkeus, double sade);
	Sylinteri(const Sylinteri & alkup);
	~Sylinteri();

	// Getters
	double annaKorkeus();
	double annaSade();

	// Setters
	void asetaKorkeus(double korkeus);
	void asetaSade(double sade);


	double tilavuus();

private:

	double korkeus_;
	double sade_;

};

