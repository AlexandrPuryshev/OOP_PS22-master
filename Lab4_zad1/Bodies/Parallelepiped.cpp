#include "stdafx.h"
#include "Parallelepiped.h"

CParallelepiped::CParallelepiped(double width, double height, double depth, double density)
	:CSolidBody(density)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
{}


CParallelepiped::~CParallelepiped(void){}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetVolume() const
{
	return m_width * m_height * m_depth;
}


string CParallelepiped::GetInformation() const
{
	ostringstream informationReturn;
	informationReturn << "CParallelepiped get started information: " << endl;
	informationReturn << "Volume: " << GetVolume() << endl;
	informationReturn << "Depth: " << GetDepth() << endl;
	informationReturn << "Height: " << GetHeight() << endl;
	informationReturn << "Width: " << GetWidth() << endl;
	informationReturn << "Density: " << GetDensity() << endl;
	informationReturn << "Mass: " << GetMass() << endl;
	return informationReturn.str();
}
