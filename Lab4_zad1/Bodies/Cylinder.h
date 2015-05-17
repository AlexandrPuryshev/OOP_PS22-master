#pragma once
#include "SolidBody.h"

using namespace std;

class CCylinder final: public CSolidBody
{
public:

	CCylinder(double radius, double height, double density);
	~CCylinder(void);

	double GetRadius() const;
	double GetHeight() const;

	virtual double GetVolume() const override;
	virtual string GetInformation() const override;

private:

	double m_height;
	double m_radius;

};

