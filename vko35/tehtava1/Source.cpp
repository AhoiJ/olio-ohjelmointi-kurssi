#include <iostream>

using std::cout; using std::cin; using std::endl;


int main()
{
	const int size = 6;

	double consumption[size] = { 7.8, 8.1, 8.05, 7.7, 7.9, 8.21 };

	for (int i = 0; i < size; i++)
		{
		cout << i + 1 << ". " << "Readout: " << consumption[i] << endl;
		}
	system("pause");
	return 0;
}