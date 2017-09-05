// vko35 tehtava3 / 4

#include <iostream>
#include <time.h>

using std::cout; using std::cin; using std::endl; using std::srand; using std::rand;

int main()
{
	const int AMOUNT = 7;
	int lotto[AMOUNT] = { {0} };
	int ownNumbers[AMOUNT] = { {0} };
	int winnings = 0;
	int check = 0;
	int test = 0;
	srand(time(NULL));

	cout << "Enter seven lottery numbers ranging from 1 to 40: ";
	// 1. K�ytt�j� sy�tt�� numeronsa ja se tarkistetaan.
		for (int i = 0; i < AMOUNT; i++)
			do
			{
				test = 0;
				cin >> ownNumbers[i];
				if (ownNumbers[i] < 1 || ownNumbers[i] > 40)
				{
					cout << "Number was not within limits" << endl;
					test++;
				}

			} while (test != 0);
	//1. P��ttyy.
		
	//2. Tulostetaan k�ytt�j�n numero.
	cout << "Here are your numbers: ";
	for (int i = 0; i < AMOUNT; i++)
		cout << ownNumbers[i] << " ";
	//2. P��ttyy.
	cout << endl << "And here are the Random numbers: ";

	//3. Numeroiden arpominen, tarkistus ettei ole samoja ja tulostus.	
	for (int i = 0; i < AMOUNT; i++)
	{
		do
		{
			check = 0;
			lotto[i] = rand() % 40 + 1;
				for (int u = 0; u < AMOUNT; u++)
					if (i != u)
					{
						if (lotto[i] == lotto[u])
							check++;
					}
		} while (check != 0);
		cout << lotto[i];
		if (i < 6)
			cout << ", ";
	}
	cout << endl;
	// 3. P��ttyy.

	// 4. Omien numeroiden vertailu arvottuihin numeroihin.
	for (int i = 0; i < AMOUNT; i++)
	{
		for (int u = 0; u < AMOUNT; u++)
			if (ownNumbers[i] == lotto[u])
				winnings++;
	}
	// 4. P��ttyy.

	// 5. Tulostetaan voittojen lukum��r�.
	cout << "You got " << winnings << " numbers right" << endl;
	// 5. P��ttyy.

	system("pause"); 
	return 0;
}
