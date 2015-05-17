
#include "stdafx.h"
#include "../Bodies/Cylinder.h"

static const double EXPECTED_RADIUS = 10;
static const double EXPECTED_HEIGHT = 5;
static const double EXPECTED_DENSITY = 10000;

struct CylinderFixture
{
	CCylinder cylinder;

	CylinderFixture()
		: cylinder(EXPECTED_RADIUS, EXPECTED_HEIGHT, EXPECTED_DENSITY)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Cylinder, CylinderFixture)

BOOST_AUTO_TEST_CASE(HasDensity)
{
	BOOST_CHECK_EQUAL(cylinder.GetDensity(), EXPECTED_DENSITY);
}

BOOST_AUTO_TEST_CASE(HasMass)
{
	double EXPECTED_MASS = cylinder.GetVolume() * cylinder.GetDensity();
	BOOST_CHECK_EQUAL(cylinder.GetMass(), EXPECTED_MASS);
}

BOOST_AUTO_TEST_CASE(HasVolume)
{
	double EXPECTED_VOLUME = (M_PI * EXPECTED_RADIUS * EXPECTED_RADIUS) * EXPECTED_HEIGHT;
	BOOST_CHECK_EQUAL(cylinder.GetVolume(), EXPECTED_VOLUME);
	CBody &body = cylinder;
	BOOST_CHECK_EQUAL(body.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(HasParameters)
{
	BOOST_CHECK_EQUAL(cylinder.GetRadius(), EXPECTED_RADIUS);
	BOOST_CHECK_EQUAL(cylinder.GetHeight(), EXPECTED_HEIGHT);
}




BOOST_AUTO_TEST_SUITE_END()