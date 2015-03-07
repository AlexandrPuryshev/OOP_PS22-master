#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <stdlib.h>

using namespace std;


void ReplaceString(ifstream &fIn, ofstream &fOut, string sSearchString, string sReplaceString, bool bFlag)
{
	int count = 0;
	while (!fIn.eof() && sSearchString.length() > 0)
	{
		string sReplacerString;
		fIn >> sReplacerString;
		char chSymbolTrancsfer = fIn.get();
		if (sReplacerString == sSearchString)
		{
			bFlag = true;
			sReplacerString = sReplaceString;
		}
		if (chSymbolTrancsfer != EOF)
		{
			sReplacerString = sReplacerString + chSymbolTrancsfer;
		}
		fOut << sReplacerString;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*if (argc != 5)
	{
		cout << "Incorrect format of input!" << endl;
		return 0;
	}*/
	string sSearchString, sReplaceString;
	sSearchString = "ma"/*(const char*)argv[3]*/;
	sReplaceString = "mama"/*(const char*)argv[4]*/;

	if ((strlen(argv[1]) > 0) && (strlen(argv[2]) > 0))
	{
		bool bFlag = false;
		ifstream fIn;
		fIn.open("inputMam.txt"/*(const char*)argv[1]*/, ios::in);
		if (fIn.fail()) // check opening of the file
		{
			cout << "Error when opening files of reading" << endl;
			fIn.close();
			return 0;
		}
		else
		{
			ofstream fOut;
			fOut.open("output1.txt"/*(const char*)argv[2]*/, ios::out);
			if (fIn.fail())
			{
				cout << "Error when opening files of writing" << endl;
				fOut.close();
				return 0;
			}
			ReplaceString(fIn, fOut, sSearchString, sReplaceString, bFlag);
			if (bFlag == false)
			{
				cout << "Such line isn't present!" << endl;
				return 0;
			}
			else
			{
				cout << "Action is executed" << endl;
			}
			fIn.close();
			fOut.close();
			return 0;
		}
	}
	else
	{
		cout << "lenght argv[1] or argv[2] <= 0!" << endl;
		return 0;
	}
	return 0;
}
