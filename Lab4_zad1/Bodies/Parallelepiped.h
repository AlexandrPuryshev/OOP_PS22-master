#pragma once
#include "SolidBody.h"
#include <string>

using namespace std;
class CParallelepiped final: public CSolidBody
{
public:

	CParallelepiped(double width, double height, double depth, double density);
	~CParallelepiped(void);

	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	virtual double GetVolume() const override;
	virtual string GetInformation() const override;

private:
	double m_width;
	double m_height;
	double m_depth;
};

