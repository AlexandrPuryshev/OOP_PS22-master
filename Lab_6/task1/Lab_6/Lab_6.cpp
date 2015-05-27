// Lab_6.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "solve3.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	vector <double> resultVec;
	pair<double, double> resultPair[3];
	EquationRoots3 resultStruct;
	int a,b,c,d, i;
	int resultCube;
	cout << "������� 4 ����������: " << endl;
	cin >> a >> b >> c >> d;
	if ( a == 1 )
	{
		try
		{
			resultCube = MethodVieta(resultVec, b, c, d);
			cout << "����� ������ ���������: " << resultCube << endl;
			resultStruct.numRoots = resultCube;
			i = 0;
			for (auto it : resultVec)
			{
				i++;
				cout << "X" << i << ")" << it << endl;
				resultStruct.roots[i - 1] = it;
			}

		}
		catch (exception e)
		{
			cout << "Error: " << e.what() << endl;
		}

	}
	else
	{
		try
		{
			resultCube = MethodKardano(resultPair, a, b, c, d);
			cout << "����� ������ ���������: " << resultCube << endl;
			resultStruct.numRoots = resultCube;
			i = 0;
			cout << "������, � ����� ������ �����: " << endl;
			for (auto it : resultPair)
			{
				i++;
				cout << "X" << i << ")" << it.first << ",  i * " << it.second << endl;
				resultStruct.roots[i - 1] = it.first;
			}
		}
		catch (exception e)
		{
			cout << "Error: " << e.what() << endl;
		}
	}
	system("pause");
	return 0;
}

