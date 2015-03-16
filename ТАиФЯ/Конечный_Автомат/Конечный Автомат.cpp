// Конечный Автомат.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>

using namespace std;

enum States
{
	State_Start,
	State_1,
	State_0,
	State_Final
};

int _tmain(int argc, _TCHAR* argv[])
{
	//States state = State_Start;
	//ifstream input_file("Signals.txt"); //в файле числа 10
	//string text;
	string MilliMatrix[3][4] =     {{ " ", "1", "2",  "3" },
						     /*x*/ { "x","1/a","2/z","1/a"}, // a и z выходные сигналы
						     /*y*/ { "y","3/a","1/a","2/z"}};

	string MyrraMatrix[4][4];
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 4; j++)
		{
			MyrraMatrix[i + 1][j] = MyrraMatrix[i][j] + MilliMatrix[i][j][0];
		}
	}

	int count = 0;
	for (int i = 1; i < 3; i++)
	{
		if (count == 3) { break; }
		for (int j = 1; j < 4; j++)
		{
			if ((isdigit(MilliMatrix[i][j][0])) && (isalpha(MilliMatrix[i][j][2]))) // если 1/a или 2/z
			{
				for (int k = 0; k < 4; k++)
				{
					if ((int(MilliMatrix[0][k][0])) == (int(MilliMatrix[i][j][0])))
					{
						count++;
						MyrraMatrix[0][j] = MyrraMatrix[0][j] + MilliMatrix[i][j][2];
					}
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		printf("\n");
		for (int j = 0; j < 4; j++)
		{
			cout << "        " << MyrraMatrix[i][j];
		}
	}
	getchar();
	return 0;
	// граф автомата
	/*const size_t length = text.length();
	for (size_t i = 0; i != length; ++i)
	{																					
		const char current = text[i];

		switch (state)
		{
		case State_Start:
			if (current == '1')
			{
				state = State_1;
			}
			else if (current == '0')
			{
				state = State_0;
			}
			break;
		case State_1:
			if (current == '0')
			{
				state = State_Final;
			}
			else
			{
				cout << "This is final state!" << endl;
			}
			break;
		case State_0:
			if (current == '1')
			{
				state = State_Final;
			}
			else
			{
				cout << "This is final state!" << endl;
			}
			break;
		case State_Final:
			if ((current != '1') || (current != '0'))
			{
				cout << "This is final state!" << endl;
			}
			break;
		}
	}*/
}

