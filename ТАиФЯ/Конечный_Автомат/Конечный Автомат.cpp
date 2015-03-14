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
	States state = State_Start;
	ifstream input_file("Signals.txt"); //в файле числа 10
	string text;
	getline(input_file, text);
	const size_t length = text.length();
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
	}
	return 0;
}

