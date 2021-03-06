#pragma once
#include "SolidBody.h"

using namespace std;

class CCone final:public CSolidBody
{
public:
	CCone(double radius, double height, double density);
	~CCone(void);

	double GetRadius() const;
	double GetHeight() const;
	double GetVolume() const override final;
	virtual string GetInformation() const override;
private:

	double m_radius;	
	double m_height;
};

