#pragma once
#include "Body.h"
class CCone:public CBody
{
public:
	CCone();
	~CCone();
	virtual double GetDensity() const override final;
	virtual double GetMass() const override final;
};

