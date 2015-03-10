// zad1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <boost/chrono.hpp>

// красивый способ
/*
for (double number : numbers)
{
cout << numbers << ", ";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
for (auto number : numbers)
{
cout << numbers << ", ";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
copy(numbers.begin(), numbers.end(), ostream_iterator<double>(Cout, ", "));
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
copy(istream_iterator<double>(Cin),istream_iterator<double>(), back_insetrter(numbers));

*/

/*for (size_t i = 0; i < Numbers.size(); ++i)
{
cout << Numbers[i] << ", ";
}*/

bool CheckSortFunction(int iValue1, int iValue2) { return (iValue1 < iValue2); }

void StdSortFunction(vector <double> &Values)
{
	sort(Values.begin(), Values.end(), CheckSortFunction);
}

void ReadingArray(vector <double> &Values)
{
	cin.setf(ios_base::fixed);
	cin.precision(3);
	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(Values));
}

void ShowVector(vector <double> &Numbers)
{
	copy(Numbers.begin(), Numbers.end(), ostream_iterator<double>(cout, ", "));
}

void MultiplyMinOnValueOfVector(vector <double> &Numbers, vector <double> &Result)
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

int main()
{
	vector <double> Numbers;
	vector <double> Result;
	ReadingArray(Numbers);
	StdSortFunction(Numbers);
	printf("\n");
	cout << "sorted source massive: ";
	ShowVector(Numbers);
	printf("\n");
	cout << "Size Source vector: " << Numbers.size() << endl;
	MultiplyMinOnValueOfVector(Numbers, Result);
	cout << "result massive after mupltiplication minimal digit on different: ";
	ShowVector(Result);
	printf("\n");
	cout << "Size Result vector: " << Result.size() << endl;
	return 0;
}