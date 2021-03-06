#include "stdafx.h"
#include "Cone.h"


CCone::CCone(double radius, double height, double density)
	:CSolidBody(density),
	m_radius(radius),
	m_height(height)
{
}


CCone::~CCone(void)
{
}

double CCone::GetRadius() const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return (M_PI / 3 * pow(m_radius, 2) * m_height);
}

string CCone::GetInformation() const
{
	ostringstream informationReturn;
	informationReturn << "CCone get started information: " << endl;
	informationReturn << "Volume: " << GetVolume() << endl;
	informationReturn << "Radius: " << GetRadius() << endl;
	informationReturn << "Height: " << GetHeight() << endl;
	informationReturn << "Density: " << GetDensity() << endl;
	informationReturn << "Mass: " << GetMass() << endl;
	return informationReturn.str();
}