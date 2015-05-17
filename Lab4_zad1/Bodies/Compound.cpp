#include "stdafx.h"
#include "Compound.h"
#include "Body.h"
#include <vector>
#include <memory>
#include <iostream>


CCompound::CCompound()
{

}


CCompound::~CCompound(void)
{

}


double CCompound::GetVolume() const
{
	return m_volume;
}

double CCompound::GetDensity() const
{
	return m_density;
}

//template<typename Derived, typename Base, typename Del>std::unique_ptr < Derived, Del >
//	void dynamic_unique_ptr_cast(std::unique_ptr<Base, Del> &&p)
//	{
//		if (Derived *result = dynamic_cast<Derived *>(p.get()))
//		{
//			p.release();
//			return std::unique_ptr<Derived, Del>(result, std::move(p.get_deleter()));
//		}
//		return std::unique_ptr<Derived, Del>(nullptr, p.get_deleter());
//	}

void CCompound::AddBody(const std::shared_ptr<CBody> &ptrBody)
{
	if (this == ptrBody.get())
	{
		return;
	}
	m_mass = m_mass + ptrBody->GetMass();
	m_volume = m_volume + ptrBody->GetVolume();
	m_density = m_mass / m_volume;
	m_vectorBody.push_back(ptrBody);
}

double CCompound::GetMass() const
{
	return m_mass;
}

size_t CCompound::GetSize() const
{
	return m_vectorBody.size();
}


string CCompound::GetInformation() const
{
	std::ostringstream informationReturn;
	informationReturn << "CCompound get started information: " << endl;
	informationReturn << "Size of elements in compound " << m_vectorBody.size() << endl;
	informationReturn << "Mass: " << GetMass() << endl;
	informationReturn << "Volume " << GetVolume() << endl;
	informationReturn << "Density: " << GetDensity() << endl;
	// возможно переделать под целый цикл
	for (auto it : m_vectorBody)
		informationReturn << it->GetInformation() << endl;
	return informationReturn.str();
}




