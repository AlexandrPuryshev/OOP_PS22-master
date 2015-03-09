#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

void vRleCompression(char *chInputString, ofstream &fOut)
{
	char *CountSymbolMass = new char[256];
	int iCount;

	char chFirstSymbol = chInputString[0];
	iCount = 0;

	for (int i = 0; i <= strlen(chInputString); i++)
	{
		if (chInputString[i] == chFirstSymbol)
		{
			iCount++;
		}
		else
		{
			if (chInputString[i - 1] != '€')
			{
				cout << "Error: 255 symbol!" << endl;
				fOut.close();
				exit(-1);
			}
			else
			{
				sprintf(CountSymbolMass, "%d", iCount);
				fOut << CountSymbolMass;
				sprintf(CountSymbolMass, "%c", chFirstSymbol);
				fOut << CountSymbolMass;
				chFirstSymbol = chInputString[i];
				iCount = 1;
			}
		}
	}
	fOut.close();
}


void vRleDecompression(ifstream &fIn, ofstream &fOut)
{
	char chSymbol;
	int iValue;
	do
	{
		fIn >> iValue >> chSymbol;
		if (fIn.eof())
		{
			break;
		}
		if ((chSymbol != '€') && (iValue < 256))
		{
			for (int i = 0; i < iValue; i++)// если символ не совпадает со слеующим символом в файле
			{
				fOut << chSymbol;// записываем результаты в выходной файл
			}
		}
		else
		{
			cout << "Error: 255 symbol!" << endl;
			fOut.close();
		}
	} while (true);
	fOut.close();
}

void FIleInTop(ifstream &fIn)
{
	fIn.clear(); // Resets the error bits
	fIn.seekg(0, ios::beg); // Sets the pointer to the top file
}

void TestStackOverflow(ifstream &fIn)
{
	string TestString;
	getline(fIn, TestString);
	if (TestString.length() > 256)
	{
		cout << "Stack overflow in input file!" << endl;
		fIn.close();
		exit(-1);
	}
}

int main(int argc, char* argv[])
{
	//////////////////////////////////////////////////////
	char *chInputString = new char[256];
	ifstream fIn;
	fIn.open((const char*)argv[2], ios::in);
	if (fIn.fail())
	{
		cout << "Error open the input file" << endl;
		fIn.close();
		return 0;
	}
	TestStackOverflow(fIn);
	FIleInTop(fIn);
	fIn >> chInputString;
	if (strcmp(chInputString, "") == 0)
	{
		cout << "file is empty!" << endl;
		fIn.close();
		return 0;
	}
	//////////////////////////////////////////////////////
	ofstream fOut;
	fOut.open((const char*)argv[3], ios::out);
	if (fOut.fail())
	{
		cout << "Error open the output file" << endl;
		fOut.close();
		return 0;
	}
	if (stricmp(argv[1], "pack") == 0)
	{
		vRleCompression(chInputString, fOut);
		fIn.close();
		cout << "crypt in outputfile!" << endl;
	}
	else if (stricmp(argv[1], "unpack") == 0)
	{
		FIleInTop(fIn);
		vRleDecompression(fIn, fOut);
		fIn.close();
		cout << "decrypt in outputfile!" << endl;
	}
	else
	{
		printf("ERR0R: serious bug was found in second parameter!");
		fIn.close();
		fOut.close();
		return 0;
	}
	return 0;
}