// Lab2_zad1_var2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <assert.h>
#include "VectorProcess.h"

void ReadingVector(vector <double> &values)
{
	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(values));
}

void ShowVector(const vector <double> &numbers)
{
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));
}


int main()
{
	vector <double> Numbers;
	vector <double> Result;
	setlocale(LC_ALL, "Russian");
	cout << "������� ������������������ ����� ����� enter: " << endl;
	cout << "����� ��������� ���� ������� �� �������� ������!" << endl;
	ReadingVector(Numbers);
	SortVectorAscending(Numbers);
	printf("\n");
	cout << "sorted source massive: ";
	ShowVector(Numbers);
	printf("\n");
	cout << "Size Source vector: " << Numbers.size() << endl;
	ProcessVector(Numbers, Result);
	Result.empty() ? cout << "result massive is empty!" :
		cout << "result massive after mupltiplication minimal digit on different: ";
	ShowVector(Result);
	printf("\n");
	cout << "Size Result vector: " << Result.size() << endl;
	getchar();
	return 0;
}
