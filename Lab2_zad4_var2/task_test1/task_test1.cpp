// task_test1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab2_zad4_var2/SetProcessor.h"

using namespace std;

BOOST_AUTO_TEST_CASE(SetUpperBound10000)
{
	BOOST_CHECK_NO_THROW(GeneratePrimeNumbersSet(10000))
}

BOOST_AUTO_TEST_CASE(SetUpperBound100000001)
{
	set<int>SetMillion = GeneratePrimeNumbersSet(100000001);
	BOOST_CHECK(SetMillion.empty());
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
