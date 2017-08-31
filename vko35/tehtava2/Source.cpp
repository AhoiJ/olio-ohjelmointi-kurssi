// vko35 tehtava2

#include <iostream>

using std::cout; using std::cin; using std::endl;

int main ()
{
	const int SIZE = 6;
	int grades[SIZE] = { 0 };
	int grade = 0;
	int students = 0;
	double average = 0;

	cout << "Please enter grades ranging from 0 to 5, to end program enter -1." << endl;
	do 	{
		cout << "Enter grade: ";
		cin >> grade;
		if (grade >= 0 && grade <= 5)
			grades[grade]++;
		if (grade > 5)
			cout << "Grade was out of limits" << endl;
	} while (grade >= 0);

	cout << "	Grade Graphical Table" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << " " << grades[i] << " ";
		for (int u = 0; u < grades[i]; u++)
			cout << "*";
		cout << endl;
	}
	
	for (int i = 0; i < SIZE; i++)
		students += grades[i];

	for (int i = 0; i < SIZE; i++)
		average += grades[i] * i;

	average = average / students;

	cout << "Amount of students: " << students << endl;
	cout << "Grade Average: " << average << endl;

	system("pause");
	return 0;
}