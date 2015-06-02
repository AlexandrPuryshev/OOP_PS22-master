#include "stdafx.h"

#include "../Bodies/Compound.h"			
#include "../Bodies/Cylinder.h"
#include "../Bodies/Sphere.h"
#include "../Bodies/Parallelepiped.h"
#include "../Bodies/Cone.h"
#include <memory>
		

const double EPS = 1e-3;

struct CompoundFixture
{
	CCompound compound;
	CCylinder cylinder;
	CCone cone;
	CSphere sphere;
	CParallelepiped parallelepiped;

	CompoundFixture()
		:compound(),
		cylinder(2, 3, 4),
		sphere(5, 10),
		parallelepiped(1, 5, 12, 123),
		cone(2, 3, 10)

	{
		compound.AddBody(make_shared<CCylinder>(cylinder));
		compound.AddBody(make_shared<CSphere>(sphere));
		compound.AddBody(make_shared<CParallelepiped>(parallelepiped));
		compound.AddBody(make_shared<CCone>(cone));
	}
};

BOOST_FIXTURE_TEST_SUITE(Compound, CompoundFixture)


BOOST_AUTO_TEST_CASE(HasMass)
{
	BOOST_CHECK_CLOSE(compound.GetMass(), sphere.GetMass() + cone.GetMass() + cylinder.GetMass() + parallelepiped.GetMass(), EPS);
}

BOOST_AUTO_TEST_CASE(HasVolume)
{
	BOOST_CHECK(compound.GetVolume() == sphere.GetVolume() +
		cone.GetVolume() + cylinder.GetVolume() + parallelepiped.GetVolume());
}

BOOST_AUTO_TEST_CASE(HasDensity)
{
	auto compoundVolume = sphere.GetVolume() + cone.GetVolume()
		+ cylinder.GetVolume() + parallelepiped.GetVolume();
	auto compounddMass = sphere.GetMass() + cone.GetMass() 
		+ cylinder.GetMass() + parallelepiped.GetMass();
	BOOST_CHECK_CLOSE(compound.GetDensity(), (compounddMass / compoundVolume), EPS);
}


BOOST_AUTO_TEST_SUITE_END()