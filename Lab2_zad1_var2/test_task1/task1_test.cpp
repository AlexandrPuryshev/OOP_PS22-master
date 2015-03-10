//TestBoost.cpp: определяет точку входа для консольного приложения.


#include "stdafx.h"
#include "../zadanie1/zad1.h"


BOOST_AUTO_TEST_CASE(EveryThingIsOk)
{
	BOOST_CHECK(2 * 2, 4);
}

//BOOST_AUTO_TEST_CASE(EmptyVectorProducesNotEmptyVector)
//{
//	vector <double> emptyVector = {};
//	ReadingArray(emptyVector);
//	BOOST_CHECK(emptyVector.empty());
//}

BOOST_AUTO_TEST_CASE(VectorMultiplyOnMinimalElementWithoutError)
{
	vector <double> Numbers = { 1.123, 12.1321, 14.12311 };
	vector <double> MinMultiplyNumbers(3);
	for (size_t i = 0; i < Numbers.size(); i++)
	{
		MinMultiplyNumbers[i] = Numbers[i] * 1.123;
	}
	vector <double> Results;
	MultiplyMinOnValueOfVector(Numbers, Results);
	BOOST_CHECK(lexicographical_compare(Numbers.begin(), Numbers.end(), Results.begin(), Results.end()));
}

BOOST_AUTO_TEST_CASE(VecotIsSorted)
{
	vector <double> Numbers = { 1.123, 1.321, 0.512, 7.12, 1.5, };
	StdSortFunction(Numbers);
	BOOST_CHECK(Numbers, { 0.512, 1.123, 1.321, 1.5, 7.12});
}

////BOOST_AUTO_TEST_CASE(ShowVectorWithoutError)
////{
////	vector <double> Numbers = { 1.123, 1.321, 0.512, 7.12, 1.5, };
////	ShowVector(Numbers);
////}