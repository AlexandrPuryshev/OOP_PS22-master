#pragma once
#include "stdafx.h"

using namespace std;

struct EquationRoots3
{
	int numRoots;
	double roots[3];
};

int MethodVieta(vector <double> &x, double a, double b, double c);
int MethodKardano(pair<double, double> x[3], double a, double b, double c, double d);