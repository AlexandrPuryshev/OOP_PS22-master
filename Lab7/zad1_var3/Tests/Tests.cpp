// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task1/FindMaxEx.h"
#include <string>

using namespace std;

BOOST_AUTO_TEST_CASE(TestEmptyVector)
{
	int max = 1;
	BOOST_CHECK(!FindMaxEx(vector<int>(), max));
	BOOST_CHECK_EQUAL(max, 1);
}

BOOST_AUTO_TEST_CASE(FindMaxValueInIntVector)
{
	int max;
	BOOST_CHECK(FindMaxEx(vector < int > { 1, 3, 5, -3, 7, 3 }, max));
	BOOST_CHECK_EQUAL(max, 7);
}

BOOST_AUTO_TEST_CASE(FindMinValueInIntVector)
{
	int min;
	BOOST_CHECK(FindMaxEx(vector < int > { 1, 3, 5, -3, 7, 3 }, min,
		[](int const& a, int const& b){ return a > b; }));

	BOOST_CHECK_EQUAL(min, -3);
}

BOOST_AUTO_TEST_CASE(TestDoubleVector)
{
	double maxValue;
	BOOST_CHECK(FindMaxEx(vector<double>({ 1.3, 3.2, 1.9, -3.8, 2.7, 3.6 }), maxValue));
	BOOST_CHECK_EQUAL(maxValue, 3.6);
}

BOOST_AUTO_TEST_CASE(FindTheHighestSportsmen)
{
	vector<Sportsman> const& sportsmen = {
		{ "Egor", 190, 75 },
		{ "Tania", 185, 80 },
		{ "Petya", 180, 95 }
	};

	{
		Sportsman tallestSportsman;

		BOOST_CHECK(FindMaxEx(sportsmen, tallestSportsman,
			[](Sportsman const& a, Sportsman const& b){ return a.height < b.height; }));

		BOOST_CHECK_EQUAL(tallestSportsman.name, "Egor");
	}
}
BOOST_AUTO_TEST_CASE(FindTheHeavySportsmen)
{
	vector<Sportsman> const& sportsmen = 
	{
		{ "Egor", 190, 85 },
		{ "Tania", 195, 100 },
		{ "Petya", 180, 90 }
	};

	{
		Sportsman heaviestSportsman;

		BOOST_CHECK(FindMaxEx(sportsmen, heaviestSportsman,
			[](Sportsman const& a, Sportsman const& b){ return a.weight < b.weight; }));

		BOOST_CHECK_EQUAL(heaviestSportsman.name, "Tania");
	}
}