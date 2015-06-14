#include "stdafx.h"
#include "SetProcessor.h"

using namespace std;


set <int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int> primeNumbers;
	if (upperBound < 2)
	{
		return primeNumbers;
	}
	vector<bool> vectrorPrime;
	vectrorPrime.resize(upperBound + 1);
	int sqrtUpperBound = (int)sqrt((double)upperBound);

	if (upperBound > 1)
	{
		vectrorPrime[2] = true;
		if (upperBound > 2)
		{
			vectrorPrime[3] = true;
		}
	}
	int i2 = 0;
	int j2 = 0;
	for (int i = 1; i <= sqrtUpperBound; ++i)
	{
		i2 += 2 * i - 1;
		j2 = 0;
		for (int j = 1; j <= sqrtUpperBound; j++)
		{
			j2 += 2 * j - 1;
			int n = 4 * i2 + j2;
			if ((n <= upperBound) && (n % 12 == 1 || n % 12 == 5))
			{
				vectrorPrime[n] = !vectrorPrime[n];
			}
			n -= i2;
			if ((n <= upperBound) && (n % 12 == 7))
			{
				vectrorPrime[n] = !vectrorPrime[n];
			}
			n -= 2 * j2;
			if ((i > j) && (n <= upperBound) && (n % 12 == 11))
			{
				vectrorPrime[n] = !vectrorPrime[n];
			}
		}
	}
	for (int i = 5; i <= sqrtUpperBound; i++)
	{
		if (vectrorPrime[i])
		{
			int n = i * i;
			for (int j = n; j <= upperBound; j += n)
			{
				vectrorPrime[j] = false;
			}
		}
	}
	for (int i = 6; i <= upperBound; i++)
	{
		if ((vectrorPrime[i]) && (i % 3 != 0) && (i % 5 != 0))
		{
			vectrorPrime[i] = true;
		}
	}

	for (int i = 2; i <= upperBound; ++i)
	{
		if (vectrorPrime[i])
		{
			primeNumbers.insert(i);
		}
	}
	return primeNumbers;
}