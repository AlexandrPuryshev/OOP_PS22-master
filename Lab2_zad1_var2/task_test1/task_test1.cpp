// task_test1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab2_zad1_var2/VectorProcess.h"

BOOST_AUTO_TEST_CASE(VectorMultiplyOnMinimalElementWithoutError)
{
	vector <double> Numbers = { 1.123, 12.1321, 14.12311 };
	vector <double> MinMultiplyNumbers(3);
	for (size_t i = 0; i < Numbers.size(); i++)
	{
		MinMultiplyNumbers[i] = Numbers[i] * 1.123;
	}
	vector <double> Results;
	ProcessVector(Numbers, Results);
	BOOST_CHECK_EQUAL_COLLECTIONS(MinMultiplyNumbers.begin(), MinMultiplyNumbers.end(), Results.begin(), Results.end());
}

BOOST_AUTO_TEST_CASE(VecorIsSorted)
{
	vector <double> Numbers = { 1.123, 1.321, 0.512, 7.12, 1.5, };
	SortVectorAscending(Numbers);
	BOOST_CHECK(Numbers == vector <double>({ 0.512, 1.123, 1.321, 1.5, 7.12 }));
}
//????????????????????????????????????????????????????????
BOOST_AUTO_TEST_CASE(VecorIsEmpty)
{
	vector <double> Numbers;
	vector <double> Results;
	ProcessVector(Numbers, Results);
	BOOST_CHECK(Numbers.empty());
} //  Assertion failed: vector iterator not dereferencable