// task_test1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab2_zad1_var2/VectorProcess.h"

BOOST_AUTO_TEST_CASE(VectorMultiplyOnMinimalElementWithoutError)
{
	vector <double> numbers = { 1.123, 12.1321, 14.12311 };
	vector <double> minMultiplyNumbers(3);
	for (size_t i = 0; i < numbers.size(); i++)
	{
		minMultiplyNumbers[i] = numbers[i] * 1.123;
	}
	vector <double> results;
	ProcessVector(numbers, results);
	BOOST_CHECK_EQUAL_COLLECTIONS(minMultiplyNumbers.begin(), minMultiplyNumbers.end(), results.begin(), results.end());
}

BOOST_AUTO_TEST_CASE(VecorIsSorted)
{
	vector <double> numbers = { 1.123, 1.321, 0.512, 7.12, 1.5, };
	SortVectorAscending(numbers);
	BOOST_CHECK(numbers == vector <double>({ 0.512, 1.123, 1.321, 1.5, 7.12 }));
}


BOOST_AUTO_TEST_CASE(VecorIsEmpty)
{
	const vector <double> numbers;
	vector <double> results;
	ProcessVector(numbers, results);
	BOOST_CHECK(numbers.empty());
}