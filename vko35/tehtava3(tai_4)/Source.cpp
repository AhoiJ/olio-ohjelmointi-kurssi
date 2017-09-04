// vko35 tehtava3 / 4

#include <iostream>
#include <time.h>


using std::cout; using std::cin; using std::endl; using std::srand; using std::rand;

int main()
{
	const int AMOUNT = 7;
	int lotto[AMOUNT] = { {0} };
	
	srand(time(NULL));

	for (int i = 0; i < AMOUNT; i++)
	{
		lotto[i] = rand() % 42 + 1;
		cout << lotto[i];
		if (i < 6)
			cout << ", ";
	}

	cout << endl;


	system("pause"); 
	return 0;



}
