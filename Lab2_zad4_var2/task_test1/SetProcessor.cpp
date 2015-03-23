#include "stdafx.h"
#include "SetProcessor.h"

using namespace std;

bool isPrime(int Value)
{
	int i;
	if (Value == 2)
		return true;
	//as if a number is not divisible by 2,then it makes no sense to divide it into 4, 6
	if (Value == 0 || Value == 1 || Value % 2 == 0)
		return false;
	//if a natural number n > 1 is not divisible by any prime number not exceeding sqrt(n), then it is simple
	for (i = 3; i * i <= Value && Value % i; i += 2);
	return i*i > Value;
}

set <int> GeneratePrimeNumbersSet(int upperBound)
{
	set <int> PrimeSet;
	if (upperBound <= 100000000)
	{
		for (int i = 0; i <= upperBound; i++)
		{
			if (isPrime(i))
			{
				PrimeSet.insert(i);
			}
		}
		return PrimeSet;
	}
	else
	{
		return PrimeSet;
	}
}