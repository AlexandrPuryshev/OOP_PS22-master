#pragma once
#include "Body.h"
class CParallelepiped : public CBody
{
public:
	CParallelepiped();
	~CParallelepiped();

	virtual double GetDensity() const override final;

	virtual double GetMass() const override final;
};

