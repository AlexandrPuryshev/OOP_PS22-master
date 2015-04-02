#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <sstream>

using namespace std;

// Function that reads a sign of number
int Sign(const float value) 
{
	return (value > 0) - (value < 0);
}

bool NuLLElementsIsExist(const float a, const float b, const float c)
{
	if (a == 0)
	{
		printf("Error: square coefficient is zero!\n");
		return 0;
	}
	if ((b == 0) && (c == 0))
	{
		printf("X=0\n");
		return 0;
	}
	if ((b == 0) || (c == 0))
	{
		if ((b == 0) && (c < 0))
		{
			printf("X1,2=+-%3.4f\n", sqrt(-c / a));
			return 0;
		}
		else if ((c == 0) && (b < 0))
		{
			printf("X1=0 \nX2=%3.4f\n", (-b / a));
			return 0;
		}
		else
		{
			printf("Error: negative coefficients!\n");
			return 0;
		}
	}
	else
	{
		return true;
	}
}

bool IsNumber(const string &string)
{
	size_t offset = 0;
	if (string[offset] == '-')
		++offset;
	return string.find_first_not_of("0123456789", offset) == std::string::npos;
}

int main(int argc, char* argv[])
{
	float a, b, c, D;
	printf("Input polynome coefficientes (ax^2+bx+c=0):\n");
	const int PARAMS_COUNT = 4;
	if (argc != PARAMS_COUNT)
	{
		cout << "Error: Invalid number of parameters!" << endl;
		return 0;
	}
	if ((IsNumber(argv[1]) == true) && (IsNumber(argv[2]) == true) &&
		(IsNumber(argv[3]) == true))
	{
		a = static_cast<float>(atoi(argv[1]));
		b = static_cast<float>(atoi(argv[2]));
		c = static_cast<float>(atoi(argv[3]));
		if (NuLLElementsIsExist(a, b, c) == true)
		{
			D = (b*b) - (4 * a*c); // discriminant
			switch (Sign(D))
			{
				case 0:
					printf("X=%3.4f\n", (-b / (2 * a))); // one root
					return 0;
				case 1:
					printf("X1=%3.4f \nX2=%3.4f\n", (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a)); // two root
					getchar();
					return 0;
				case -1:
					printf("There is no real root\n"); // there are no roots
					return 0;
			}
		}
	}
	else
	{
		printf("There is no digits!\n");
	}
}
