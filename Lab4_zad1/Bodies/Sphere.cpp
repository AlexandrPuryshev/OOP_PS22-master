#include "stdafx.h"
#include "Sphere.h"

CSphere::CSphere(double radius, double density)
	: CSolidBody(density)
	, m_radius(radius)
{

}

CSphere::~CSphere(void)
{

}

double CSphere::GetRadius() const
{
	return m_radius;
}

double CSphere::GetVolume() const
{
	return (4 * M_PI / 3 * pow(m_radius, 3));
}

string CSphere::GetInformation() const
{
	ostringstream informationReturn;
	informationReturn << "CSphere get started information: " << endl;
	informationReturn << "Volume: " << GetVolume() << endl;
	informationReturn << "Radius: " << GetRadius() << endl;
	informationReturn << "Density: " << GetDensity() << endl;
	informationReturn << "Mass: " << GetMass() << endl;
	return informationReturn.str();
}

