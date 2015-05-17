// Bodies.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Body.h"
#include "Compound.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Sphere.h"
#include <exception>
#include <iomanip>

shared_ptr<CBody>AddCompound(int selectOperation);
shared_ptr<CBody>AddBody(int &selectOperation);
void SelectCommands(vector<shared_ptr<CBody>> &vectorBody);
using namespace std;

shared_ptr<CBody>AddCone()
{
	double radius;
	double height;
	double density;
	cout << "Radius, height and density" << endl;
	if (cin >> radius >> height >> density)
	{
		return make_shared<CCone>(radius, height, density);
	}
	return nullptr;
}

shared_ptr<CBody>AddCylinder()
{
	double radius;
	double height;
	double density;
	cout << "Radius, height and density" << endl;
	if (cin >> radius >> height >> density)
	{
		return make_shared<CCylinder>(radius, height, density);
	}
	return nullptr;
}


shared_ptr<CBody>AddParallelepiped()
{
	double width;
	double height;
	double depth;
	double density;
	cout << "width, height, depth and density" << endl;
	if (cin >> width >> height >> depth >> density)
	{
		return make_shared<CParallelepiped>(width, height, depth, density);
	}
	return nullptr; // что возвращать???
}

shared_ptr<CBody>AddSphere()
{
	double radius;
	double density;
	cout << "radius and density" << endl;
	if (cin >> radius >> density)
	{
		return make_shared<CSphere>(radius, density);
	}
	return nullptr;
}


shared_ptr<CBody>AddCompound(int selectOperation)
{
	CCompound *compound_ptr = new CCompound(); //неправильное выделение памяти?
	shared_ptr<CBody>body;
	while ((body = AddBody(selectOperation)) != nullptr)
	{
		compound_ptr->AddBody(body); // вносятся какие то неправильные парамтеры!!!
	}
	if (compound_ptr->GetSize() == 0)
	{
		cout << "Error of add empty body -> return nullptr" << endl;
		return nullptr;
	}
	else
	{
		auto compound_shared_ptr = make_shared<CCompound>(*compound_ptr);
		delete compound_ptr;
		return compound_shared_ptr;

	}
}
//переделать код под норм выделение памяти...
shared_ptr<CBody>AddBody(int &selectOperation)
{
	shared_ptr<CBody>body;
	cout << "---------------------------------" << endl;
	cout << " 1: cone" << endl
		<< " 2: cylinder" << endl
		<< " 3: parallelepiped" << endl
		<< " 4: sphere" << endl
		<< " 5: compound" << endl
		<< " 6: information" << endl
		<< "for exit: enter symbol: 0" << endl;
	cout << "Choose the operation: ";
	if (cin >> selectOperation)
	{
		cout << "---------------------------------" << endl;
		switch (selectOperation)
		{
		case 1: { body = AddCone(); break; }
		case 2: { body = AddCylinder(); break; }
		case 3: { body = AddParallelepiped(); break; }
		case 4: { body = AddSphere(); break; }
		case 5: { body = AddCompound(selectOperation);break;}
		}
		//при выборе 5, а потом 0 selectOperation = 5...
		if ((selectOperation < 1) || (selectOperation > 5)) // не выбирается selectOperation???
		{
			return nullptr;
		}
		else
		{
			return body;
		}
	}
	else
	{
		cout << "Error of input! " << endl;
		return nullptr;
	}
}

void SelectCommands(vector<shared_ptr<CBody>> &vectorBody)
{
	shared_ptr<CBody>body;
	int selectOperation = 1;
	if ((body = AddBody(selectOperation)) != nullptr)
	{
		vectorBody.push_back(body);
		while (selectOperation != 0 || body != nullptr)
		{
			if ((body = AddBody(selectOperation)) != nullptr)
			{
				vectorBody.push_back(body);
			}
		}
	}
}

void CompareArchimedesForces(vector<shared_ptr<CBody>> bodies)
{
	const double waterDensity = 1000;
	const double g = 9.81;
	auto maxMass = bodies[0];
	auto lightestInWater = bodies[0];
	double minArch = (bodies[0]->GetDensity() - waterDensity) * bodies[0]->GetVolume();
	for (auto &it : bodies)
	{
		if (maxMass->GetMass() < it->GetMass())
		{
			maxMass = it;
		}
		if (minArch > (it->GetDensity() - waterDensity) * it->GetVolume())
		{
			lightestInWater = it;
			minArch = (it->GetDensity() - waterDensity) * it->GetVolume();
		}
	}
	cout << "Max mass: " << endl;
	cout << maxMass->GetInformation() << endl;

	cout << "lightest in water is: " << endl;
	cout << lightestInWater->GetInformation() << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	shared_ptr<CBody>body;
	vector<shared_ptr<CBody>> vectorBody;
	size_t count = 0;
	SelectCommands(vectorBody);
	if (vectorBody.empty())
	{
		cout << "bodies is empty!" << endl;
		return 0;
	}
	CompareArchimedesForces(vectorBody);
	//for (CBody *it : bodies) 
	//{
	//	delete it;
	//}
	getchar();
	return 0;
}


