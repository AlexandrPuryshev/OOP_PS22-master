#include "stdafx.h"
#include "Cylinder.h"

CCylinder::CCylinder(double radius, double height, double density)
	: CSolidBody(density),
	m_radius(radius),
	m_height(height)
{}

CCylinder::~CCylinder(void)
{}

double CCylinder::GetRadius() const
{
	return m_radius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return M_PI * m_radius * m_radius * m_height;
}

string CCylinder::GetInformation() const
{
	ostringstream informationReturn;
	informationReturn << "CCylinder get started information: " << endl;
	informationReturn << "Volume: " << GetVolume() << endl;
	informationReturn << "Radius: " << GetRadius() << endl;
	informationReturn << "Height: " << GetHeight() << endl;
	informationReturn << "Density: " << GetDensity() << endl;
	informationReturn << "Mass: " << GetMass() << endl;
	return informationReturn.str();
}