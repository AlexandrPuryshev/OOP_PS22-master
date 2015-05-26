// task1tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab_6/solve3.h"

using namespace std;

const double EPS = 1e-2;

BOOST_AUTO_TEST_CASE(FirstRootIsZero)
{
	int result;
	vector<double>Vec;
	pair<double, double>Par[3];

	{
		try
		{
			result = MethodVieta(Vec, 0, 1, 15);
			BOOST_CHECK(false);
		}
		catch (invalid_argument)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			result = MethodKardano(Par, 0, 1, 15, 1);
			BOOST_CHECK(false);
		}
		catch (invalid_argument)
		{
			BOOST_CHECK(true);
		}
	}
}

BOOST_AUTO_TEST_CASE(TheRealRoots)
{
	int result;
	vector<double>Vec;
	pair<double, double>Par[3];

	{
		try
		{
			result = MethodKardano(Par, 2, 6, 7, 1);
			BOOST_CHECK(result == 3);
			BOOST_CHECK_CLOSE(Par[0].first, -0.164878, EPS);
			BOOST_CHECK(true);
		}
		catch (exception)
		{
			BOOST_CHECK(false);
		}
	}
}

