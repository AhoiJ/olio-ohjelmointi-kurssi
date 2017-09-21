#include <iostream>
#include "Date.h"

using std::cout; using std::endl;

int main()
{
	Date Today; // With default builder
	Today.print();

	Date Tomorrow(15, 9, 2017); // with paramter builder
	Tomorrow.print();

	return 0;
}