#include "stdafx.h"
#include "VectorProcess.h"

void SortVectorAscending(vector <double> &values)
{
	sort(values.begin(), values.end());
}


void ProcessVector(const vector <double> &numbers, vector <double> &result)
{
	if (!numbers.empty())
	{
		double minElemntInVector = *min_element(numbers.begin(), numbers.end());
		for (
			vector<double>::const_iterator it = numbers.begin();
			it != numbers.end();
		++it
			)
		{
			result.push_back(*it * minElemntInVector);
		}
	}
}