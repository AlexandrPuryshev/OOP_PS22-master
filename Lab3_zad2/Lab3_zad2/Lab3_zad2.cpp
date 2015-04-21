// Lab3_zad2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iosfwd>
#include <sstream>

using namespace std;

int switchFunc(string buf, string* protoCommands)
{
	for (int i = 0; i < 3; ++i)
	{
		if (buf == protoCommands[i])
		{
			return i;
		}
	}
	return -1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	CRectangle rectang;
	stringstream ss;
	string line;
	ifstream inputFile1("input1.txt"); // argv[..]!
	if (!(inputFile1.is_open()))
	{
		return 0;
	}

	string* commands = new string[3]
	{
			"Move",
			"Scale",
			"Rectangle",
	};

	while (getline(inputFile1, line))
	{
		ss << line;
		string commandInLine;
		int left, top, width, height;
		ss >> commandInLine;
		if (line.find('\n') == std::string::npos)
		{
			switch (switchFunc(commandInLine, commands))
			{
			case 0:
			{
				cout << "0";
				break;
			}
			case 1:
			{
				cout << "1";
				break;
			}
			case 2:
			{
				cout << "2";
				break;
			}
			}

			int digit = atoi(line.c_str());
			if (digit)
			{
				cout << "is digit" << endl;
			}
		}
	}


}
