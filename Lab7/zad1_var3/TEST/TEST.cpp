// TEST.cpp : Defines the entry point for the console application.
//
// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../LAB7-2/Headerh.h"

BOOST_AUTO_TEST_CASE(TestEmptyVector)
{
	int max = 1;
	BOOST_CHECK(!FindMaxEx(vector<int>(), max));
	BOOST_CHECK_EQUAL(max, 1);
}

BOOST_AUTO_TEST_CASE(TestIntVector)
{
	int maxValue;
	BOOST_CHECK(FindMaxEx(vector<int>({ 1, 3, 5, -3, 7, 3 }), maxValue));
	BOOST_CHECK_EQUAL(maxValue, 7);
}

BOOST_AUTO_TEST_CASE(FindMinValueInIntVector)
{
	int min;
	BOOST_CHECK(FindMaxEx(vector<int>{ 9, 0, -2, 6, 4, 8 }, min,
		[](int const& a, int const& b){ return a > b; }));

	BOOST_CHECK_EQUAL(min, -2);
}

BOOST_AUTO_TEST_CASE(TestDoubleVector)
{
	double maxValue;
	BOOST_CHECK(FindMaxEx(vector<double>({ 1.3, 3.2, 1.9, -3.8, 2.7, 3.6 }), maxValue));
	BOOST_CHECK_EQUAL(maxValue, 3.6);
}

BOOST_AUTO_TEST_CASE(FindTheHighestSportsman)
{
	vector<Sportsman> const& sportsmen =
	{
		{ "Pasha", 190, 75 },
		{ "Egor", 185, 80 },
		{ "Petya", 180, 95 }
	};

	{
		Sportsman tallestSportsman;

		BOOST_CHECK(FindMaxEx(sportsmen, tallestSportsman,
			[](Sportsman const& a, Sportsman const& b){ return a.height < b.height; }));

		BOOST_CHECK_EQUAL(tallestSportsman.name, "Pasha");
	}
}
BOOST_AUTO_TEST_CASE(FindTheHeavySportsman)
{
	vector<Sportsman> const& sportsmen =
	{
		{ "Pasha", 190, 85 },
		{ "Egor", 195, 100 },
		{ "Petya", 180, 90 }
	};

	{
		Sportsman heaviestSportsman;

		BOOST_CHECK(FindMaxEx(sportsmen, heaviestSportsman,
			[](Sportsman const& a, Sportsman const& b){ return a.weight < b.weight; }));

		BOOST_CHECK_EQUAL(heaviestSportsman.name, "Egor");
	}
}
