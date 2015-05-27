// task1tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab_6/solve3.h"

using namespace std;

const double EPS = 1e-3;

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

BOOST_AUTO_TEST_CASE(SqrtLessZero)
{
	int result;
	vector<double>Vec;
	{
		try
		{
			result = MethodVieta(Vec, 2, 7, 1);
			BOOST_CHECK(false);
		}
		catch (exception)
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
			BOOST_CHECK_CLOSE(Par[1].first, -1.41756, EPS);
			BOOST_CHECK_CLOSE(Par[2].first, -1.41756, EPS);
			// мнимая часть
			BOOST_CHECK(Par[0].second == 0);
			BOOST_CHECK_CLOSE(Par[1].second, 1.01147, EPS);
			BOOST_CHECK_CLOSE(Par[2].second, -1.01147, EPS);
			BOOST_CHECK(true);
		}
		catch (exception)
		{
			BOOST_CHECK(false);
		}
	}

	{
		try
		{
			result = MethodVieta(Vec, 12, 7, 2);
			BOOST_CHECK(result == 3);
			BOOST_CHECK_CLOSE(Vec[0], -381.47279115365973, EPS);
			BOOST_CHECK_CLOSE(Vec[1], 185.24387259604333, EPS);
			BOOST_CHECK_CLOSE(Vec[2], 184.22891855761640, EPS);
			BOOST_CHECK(true);
		}
		catch (exception)
		{
			BOOST_CHECK(false);
		}
	}

}



