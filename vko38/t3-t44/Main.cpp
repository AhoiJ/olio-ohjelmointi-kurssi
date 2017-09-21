#include "Oppilas.h"

int main()
{
	Oppilas ossi;
	Oppilas oona("1234", "Oona", "Opiskelija", "oona@koulu.fi");

	ossi.tulosta();
	oona.tulosta();

	ossi.asetaEmail("ossi@koulu.fi");
	ossi.asetaNim("Ossi");
	ossi.asetaNum("4321");

	ossi.tulosta();

	system("pause");






}