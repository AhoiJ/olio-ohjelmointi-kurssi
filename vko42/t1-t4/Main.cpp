#include <iostream>
#include "Koulu.h"


int main()
{
	Koulu tamk("TAMK");

	tamk.lisaaKoulutusohjelma();
	tamk.lisaaKoulutusohjelmaanOpettaja();
	tamk.lisaaKoulutusohjelmaanOpiskelija();

	tamk.tulostaKoulutusohjelmanOpettajat();
	tamk.tulostaKoulutusohjelmanOppilaat();

	system("pause");
	return 0;
}