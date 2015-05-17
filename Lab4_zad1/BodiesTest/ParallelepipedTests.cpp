#include "stdafx.h"
#include "../Bodies/Parallelepiped.h"

static const double EXPECTED_WIDTH = 4;
static const double EXPECTED_HEIGHT = 4;
static const double EXPECTED_DEPTH = 2;
static const double EXPECTED_DENSITY = 3000;

struct ParallelepipedFixture
{
	CParallelepiped parallelepiped;

	ParallelepipedFixture()
		:parallelepiped(EXPECTED_WIDTH, EXPECTED_HEIGHT, EXPECTED_DEPTH, EXPECTED_DENSITY)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Parallelepiped, ParallelepipedFixture)

BOOST_AUTO_TEST_CASE(HasVolume)
{
	double EXPECTED_VOLUME = EXPECTED_WIDTH * EXPECTED_HEIGHT * EXPECTED_DEPTH;
	BOOST_CHECK_EQUAL(parallelepiped.GetVolume(), EXPECTED_VOLUME);
	CBody &body = parallelepiped;
	BOOST_CHECK_EQUAL(body.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(HasDensity)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetDensity(), EXPECTED_DENSITY);
}

BOOST_AUTO_TEST_CASE(HasParameters)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetWidth(), EXPECTED_WIDTH);
	BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), EXPECTED_HEIGHT);
	BOOST_CHECK_EQUAL(parallelepiped.GetDepth(), EXPECTED_DEPTH);
}

BOOST_AUTO_TEST_CASE(HasMass)
{
	double EXPECTED_MASS = parallelepiped.GetVolume() * parallelepiped.GetDensity();
	BOOST_CHECK_EQUAL(parallelepiped.GetMass(), EXPECTED_MASS);
}


BOOST_AUTO_TEST_SUITE_END()