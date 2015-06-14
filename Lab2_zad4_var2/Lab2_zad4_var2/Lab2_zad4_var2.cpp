// Lab2_zad4_var2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "SetProcessor.h"
using namespace std;

int main()
{
	set <int> Set;
	Set = GeneratePrimeNumbersSet(10);
	for (set<int>::const_iterator it = Set.begin();
		it != Set.end();
		it++)
	{
		cout << *it << ",";
	}
	printf("\n");
	system("pause");
}

