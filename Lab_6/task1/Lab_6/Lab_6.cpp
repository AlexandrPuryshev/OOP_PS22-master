// Lab_6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "solve3.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	vector <double> result;
	pair<double, double> resultPair[3];
	int a,b,c,d, i;
	int resultCube;
	cout << "ВВедите 4 переменных: " << endl;
	cin >> a >> b >> c >> d;
	if ( a == 1 )
	{
		try
		{
			resultCube = MethodVieta(result, b, c, d);
			cout << "Всего корней уравнения: " << resultCube << endl;
			i = 0;
			for (auto it : result)
			{
				i++;
				cout << "X" << i << ")" << it << endl;
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
			cout << "Всего корней уравнения: " << resultCube << endl;
			i = 0;
			cout << "корень, а затем мнимая часть: " << endl;
			for (auto it : resultPair)
			{
				i++;
				cout << "X" << i << ")" << it.first << ",  i * " << it.second << endl;
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

