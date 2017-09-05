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

	cout << "Enter seven lottery numbers ranging from 1 to 42: ";

		for (int i = 0; i < AMOUNT; i++)
			do
			{
				test = 0;
				cin >> ownNumbers[i];
				if (ownNumbers[i] < 1 || ownNumbers[i] > 42)
				{
					cout << "Number was not within limits" << endl;
					test++;
				}

			} while (test != 0);
		cout << "Here are your numbers: ";

	for (int i = 0; i < AMOUNT; i++)
		cout << ownNumbers[i] << " ";

	cout << endl << "And here are the Random numbers: ";

	for (int i = 0; i < AMOUNT; i++)
	{
		do
		{
			check = 0;
			lotto[i] = rand() % 42 + 1;
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
	
	for (int i = 0; i < AMOUNT; i++)
	{
		for (int u = 0; u < AMOUNT; u++)
			if (ownNumbers[i] == lotto[u])
				winnings++;
	}

	cout << "You got " << winnings << " numbers right" << endl;

	system("pause"); 
	return 0;
}
