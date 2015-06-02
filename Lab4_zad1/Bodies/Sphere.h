#pragma once
#include "Solidbody.h"

class CSphere final : public CSolidBody
{
public:
	CSphere(double radius, double density);
	~CSphere(void);

	double GetRadius() const;
	double GetVolume() const override final;
	std::string GetInformation() const override;

private:
	double m_radius;
};

