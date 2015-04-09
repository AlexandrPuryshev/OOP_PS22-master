#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

void RleCompression(char *chInputString, ofstream &fileOutput)
{
	char *CountSymbolMass = new char[256];
	long count = 0;

	char chFirstSymbol = chInputString[0];

	for (size_t i = 0; i <= strlen(chInputString); ++i)
	{
		if (chInputString[i] == chFirstSymbol)
		{
			count++;
		}
		else
		{
			if ((int)chInputString[i] == -96 || (int)chInputString[0] == -96)
			{
				cout << "Error: 255 ascii code symbol!" << endl;
				fileOutput.close();
				exit(0);
			}
			else
			{
				sprintf_s(CountSymbolMass, 5, "%d%c", count, chFirstSymbol);
				fileOutput << CountSymbolMass;
				chFirstSymbol = chInputString[i];
				count = 1;
			}
		}
	}
	fileOutput.close();
}


void RleDecompression(ifstream &fileInput, ofstream &fileOutput)
{
	char symbol;
	int value;
	do
	{
		fileInput >> value >> symbol;
		if (fileInput.eof())
		{
			break;
		}
		if (((int)symbol != -96) && (value < 256))
		{
			for (int i = 0; i < value; i++)// если символ не совпадает со слеующим символом в файле
			{
				fileOutput << symbol;// записываем результаты в выходной файл
			}
		}
		else
		{
			cout << "Error: 255 ascii code symbol or length > 256!" << endl;
			fileOutput.close();
			exit(0);
		}
	} while (true);
	fileOutput.close();
}

void FIleInTop(ifstream &fileInput)
{
	fileInput.clear(); // Resets the error bits
	fileInput.seekg(0, ios::beg); // Sets the pointer to the top file
}

void TestStringOverflow(ifstream &fileInput)
{
	string TestString;
	getline(fileInput, TestString);
	if (TestString.length() > 256)
	{
		cout << "String overflow in input file!" << endl;
		fileInput.close();
		exit(0);
	}
}

int main(int argc, char* argv[])
{
	//////////////////////////////////////////////////////
	const int PARAMS_COUNT = 4;
	if (argc != PARAMS_COUNT)
	{
		cout << "Incorrect format of input!" << endl;
		return 0;
	}
	char *chInputString = new char[256];
	ifstream fileInput((const char*)argv[2], ios::in | ios::binary);
	if (!fileInput.is_open())
	{
		cout << "Error open the input file" << endl;
		return 0;
	}
	TestStringOverflow(fileInput);
	FIleInTop(fileInput);
	fileInput >> chInputString;
	if (strcmp(chInputString, "") == 0)
	{
		cout << "file is empty!" << endl;
		return 0;
	}
	//////////////////////////////////////////////////////
	ofstream fileOutput;
	fileOutput.open((const char*)argv[3], ios::out | ios::binary);
	if (fileOutput.fail())
	{
		cout << "Error open the output file" << endl;
		return 0;
	}
	if (_stricmp(argv[1], "pack") == 0)
	{
		RleCompression(chInputString, fileOutput);
		cout << "crypt in outputfile!" << endl;
	}
	else if (_stricmp(argv[1], "unpack") == 0)
	{
		FIleInTop(fileInput);
		RleDecompression(fileInput, fileOutput);
		cout << "decrypt in outputfile!" << endl;
	}
	else
	{
		printf("ERR0R: serious bug was found in second parameter!");
		return 0;
	}
	//////////////////////////////////////////////////////
	return 0;
}