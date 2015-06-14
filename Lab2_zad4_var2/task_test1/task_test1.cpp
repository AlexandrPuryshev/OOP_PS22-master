// task_test1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab2_zad4_var2/SetProcessor.h"

using namespace std;

BOOST_AUTO_TEST_CASE(TwoSetIsEqual)
{
	set<int>testSet = GeneratePrimeNumbersSet(10);
	set<int>testSet2 = GeneratePrimeNumbersSet(10);
	BOOST_CHECK(testSet.size() == 4);
	BOOST_CHECK(testSet2.size() == 4);
	BOOST_CHECK(testSet == testSet2);
}

BOOST_AUTO_TEST_CASE(SetUpperBound3)
{
	set<int>testSet = GeneratePrimeNumbersSet(3);
	set<int>testSet2;
	BOOST_CHECK(testSet.size() == 2);
	testSet2.insert(2);
	testSet2.insert(3);
	assert(testSet == testSet2);
}

BOOST_AUTO_TEST_CASE(SetUpperBoundIsNegativeElement)
{
	set<int>SetNegative = GeneratePrimeNumbersSet(-11);
	BOOST_CHECK(SetNegative.empty());
}

BOOST_AUTO_TEST_CASE(SetUpperBoundIsZeroElement)
{
	set<int>SetZero= GeneratePrimeNumbersSet(0);
	BOOST_CHECK(SetZero.empty());
}
