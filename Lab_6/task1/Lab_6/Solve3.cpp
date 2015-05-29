/* Решение кубического уравнения
	алгоритм
	//http://www.dpva.info/Guide/GuideMathematics/Equations/cubeEquationsUniversalMethods/
*/

#include "stdafx.h"
#include "solve3.h"
#include <iostream>
#include <cerrno>
#include <cfenv>

#pragma STDC FENV_ACCESS ON

#define Sign(x)( x<0? -x : x)

using namespace std;

double isNegativeCubeRoots(double x)
{
	if (x < 0)
		return -pow(-x, 1.0 / 3.0);
	return pow(x, 1.0 / 3.0);
}

double GetArchX(double x)
{
	// error handling
	//http://en.cppreference.com/w/cpp/numeric/math/sqrt
	double checkNegativeValue = sqrt(x * x - 1);
	if (errno == EDOM)
	{ 
		throw exception("errno = EDOM, sqrt have negative value!");
		return 0;
	}
	else
	{ 
		return log(x + checkNegativeValue);
	}
}


//y^3 + py + q = 0;
int MethodKardano(pair<double, double> x[3], double a, double b, double c, double d)
{
	if (a == 0)
	{
		throw invalid_argument("a == 0");
	}
	// error handling
	//http://en.cppreference.com/w/cpp/numeric/math/sqrt
	errno = 0;
	std::feclearexcept(FE_ALL_EXCEPT);
	double p, q, S, angle;
	p = (3.0*a*c - b*b) / (3.0*a*a);
	q = (2.0*b*b*b - 9.0*a*b*c + 27.0*a*a*d) / (27.0*a*a*a);
	S = (q*q / 4.0) + (p*p*p / 27.0);
	//////////////////////////////////////////////////////////////////////////////
	if (q == 0)
		angle = M_PI / 2.0;
	if (q < 0)
		angle = atan(-2.0 * sqrt(S) / q);
	if (q > 0)
		angle = atan(-2.0 * sqrt(S) / q) + M_PI;
	//////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 3; i++)
	{ 
		x[i].first = x[i].second = 0;
	}
	//////////////////////////////////////////////////////////////////////////////
	if (S < 0)
	{
		double checkNegativeValue = sqrt(-p / 3.0);
		if (errno == EDOM)
		{
			throw exception("errno = EDOM, sqrt have negative value!");
			return 0;
		}
		x[0].first = 2.0 * checkNegativeValue*cos(angle / 3.0) - b / (3.0 * a);
		x[1].first = 2.0 * checkNegativeValue*cos((angle / 3.0) + 2.0*M_PI / 3.0) - b / (3.0 * a);
		x[2].first = 2.0 * checkNegativeValue*cos((angle / 3.0) + 4.0*M_PI / 3.0) - b / (3.0 * a);
		return 1;
	}
	else if (S == 0)
	{
		x[0].first = 2.0 * isNegativeCubeRoots(-q / 2.0) - b / (3.0 * a);
		x[1].first = -isNegativeCubeRoots(-q / 2.0) - b / (3.0 * a);
		x[2].first = -isNegativeCubeRoots(-q / 2.0) - b / (3.0 * a);
		return 2;
	}
	else if (S > 0)
	{
		double temp1 = isNegativeCubeRoots((-q / 2.0) + sqrt(S)) + isNegativeCubeRoots((-q / 2.0) - sqrt(S));
		double temp2 = isNegativeCubeRoots((-q / 2.0) + sqrt(S)) - isNegativeCubeRoots((-q / 2.0) - sqrt(S));
		if (errno == EDOM)
		{
			throw exception("errno = EDOM, sqrt have negative value!");
			return 0;
		}
		x[0].first = temp1 - b / (3.0 * a);
		x[1].first = -temp1 / 2.0 - b / (3.0 * a); x[1].second = sqrt(3)*temp2 / 2.0;
		x[2].first = -temp1 / 2.0 - b / (3.0 * a); x[2].second = -sqrt(3)*temp2 / 2.0;
		return 3;
	}
	return 0;

}


//x3 + ax2 + bx + c = 0
int MethodVieta(vector <double> &x, double a, double b, double c)
{
	if (a == 0)
	{
		throw invalid_argument("a == 0");
	}
	errno = 0;
	std::feclearexcept(FE_ALL_EXCEPT);
	double q, r, rSquare, qSquare, s, Sqrt_2_q;
	q = (a * a - 3.0 * b) / 9.0; 
	r = (a * (2.0 * a * a - 9.0 * b) + 27.0 * c) / 54.0;
	rSquare = r * r;
	qSquare = q * q * q;
	s = qSquare - rSquare;
	//////////////////////////////////////////////////////////////////////////////
	if (s > 0)
	{
		//уравнение имеет 3 корня(вещественных) :
		double angle = (acos(r / sqrt(pow(qSquare, 3.0)))) / 3.0;
		Sqrt_2_q = 2.0 * sqrt(q);
		if (errno == EDOM)
		{
			throw exception("errno = EDOM, sqrt have negative value!");
			return 0;
		}
		x.push_back(-Sqrt_2_q * cos(angle) - a / 3.0);
		x.push_back(-Sqrt_2_q * cos(angle + (2.0 * M_PI / 3.0)) - a / 3.0);
		x.push_back(-Sqrt_2_q * cos(angle - (2.0 * M_PI / 3.0)) - a / 3.0);
		return 3;
	}
	else if (s < 0)
	{
		double angle = (GetArchX(fabs(r) / sqrt(pow(fabs(q), 3)))) / 3.0;
		if (angle != 0)
		{
			double expression = (((-2.0 * Sign(r) * sqrt(fabs(q)) * ((pow(M_E, angle) + pow(M_E, -angle)) / 2))) - a / 3.0);
			double exceptionWithout_2 = (((Sign(r) * sqrt(fabs(q)) * ((pow(M_E, angle) + pow(M_E, -angle)) / 2))) - a / 3.0);
			double expression2 = ((3.0 * sqrt(fabs(q)) * ((pow(M_E, angle) - pow(M_E, -angle)) / 2.0)));
			cout << "1) единственный корень (вещественный)" << endl;
			x.push_back(expression);
			cout << "2) мнимые корни 2 и 3" << endl;
			x.push_back(exceptionWithout_2 + expression2);
			x.push_back(exceptionWithout_2 - expression2);
			return 3;
		}
		else
		{
			throw exception("errno = EDOM, sqrt have negative value!");
			return 0;
		}
	}
	//уравнение имеет меньше трех различных решений:
	else if (s == 0)
	{
		x.push_back(-2 * cbrt(r) - a / 3.0);
		x.push_back(cbrt(r) - a / 3.0);
		x.push_back(cbrt(r) - a / 3.0);
		return 3;
	}
	return 0;
}