#include "stdafx.h"
#include "VectorProcess.h"

void SortVectorAscending(vector <double> &Values)
{
	sort(Values.begin(), Values.end());
}


void ProcessVector(vector <double> &Numbers, vector <double> &Result)
{
	for (
		vector<double>::const_iterator it = Numbers.begin();
		it != Numbers.end();
	++it
		)
	{
		Result.push_back(*it * *min_element(Numbers.begin(), Numbers.end()));
	}
}