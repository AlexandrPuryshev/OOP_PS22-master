#pragma once
#include "Body.h"
#include <vector>
#include <memory>

using namespace std;

class CCompound: public CBody
{
public:

	CCompound();

	~CCompound(void);


	virtual double GetVolume() const override final;
	virtual double GetMass() const override final;
	virtual double GetDensity() const override final;
	virtual string GetInformation() const override final;
	size_t GetSize() const;
	void AddBody(const std::shared_ptr<CBody>&ptrBody);

private:
	double m_mass;
	double m_volume;
	double m_density;
	std::vector<std::shared_ptr<CBody>> m_vectorBody;

};

