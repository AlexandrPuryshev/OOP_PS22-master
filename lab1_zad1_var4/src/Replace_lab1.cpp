#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <assert.h>

using namespace std;

void ReplaceStringsInString(string SearchString, string ReplaceString, string &ReplacerString)
{
	size_t i, j;
	size_t iLenStr = SearchString.length();
	for (i = 0; i <= ReplacerString.size() - SearchString.size(); i++)
	{
		for (j = 0; j + 1 < SearchString.size(); j++)
		{
			if (ReplacerString[i + j] != SearchString[j]) { break; }
		}
		if (j + 1 == SearchString.size())
		{
			ReplacerString.replace(i, j, ReplaceString);
			i += SearchString.size();
		}
	}
}

void ReplaceStringInFile(ifstream &fIn, ofstream &fOut, string SearchString, string ReplaceString, bool &StringIsFound)
{
	while (!fIn.eof() && SearchString.length() > 0)
	{
		string ReplacerString;
		fIn >> ReplacerString;
		size_t Position = ReplacerString.find(SearchString);
		char SymbolTrancsfer = fIn.get();
		if ((Position != std::string::npos) && (ReplacerString.size() > SearchString.size()))
		{
			StringIsFound = true;
			ReplaceStringsInString(SearchString, ReplaceString, ReplacerString);
		}
		else if (ReplacerString == SearchString)
		{
			StringIsFound = true;
			ReplacerString = ReplaceString;
		}
		if (SymbolTrancsfer != EOF)
		{
			ReplacerString = ReplacerString + SymbolTrancsfer;
		}
		fOut << ReplacerString;
	}
}

void OpenFilesAndReplaceStrings(string SearchString, string ReplaceString, char* &FileArgument1, char* &FileArgument2)
{
	if ((strlen(FileArgument1) > 0) && (strlen(FileArgument2) > 0))
	{
		bool StringIsFound = false;
		ifstream fIn;
		fIn.open(FileArgument1, ios::in);
		if (fIn.fail()) // check opening of the file
		{
			cout << "Error when opening files of reading" << endl;
			exit(-1);
		}
		else
		{
			ofstream fOut;
			fOut.open((const char*)FileArgument2, ios::out);
			if (fOut.fail())
			{
				cout << "Error when opening files of writing" << endl;
				exit(-1);
			}
			ReplaceStringInFile(fIn, fOut, SearchString, ReplaceString, StringIsFound);
			if (StringIsFound == false)
			{
				cout << "Such line isn't present!" << endl;
			}
			else
			{
				cout << "Action is executed" << endl;
			}
		}
	}
	else
	{
		cout << "Such file isn't present!" << endl;
		exit(-1);
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int PARAMS_COUNT = 5;
	if (argc != PARAMS_COUNT)
	{
		cout << "Incorrect format of input!" << endl;
		return 0;
	}
	string SearchString, ReplaceString;
	SearchString = (const char*)argv[3];
	ReplaceString = (const char*)argv[4];
	char* FileArgument1 = argv[1];
	char* FileArgument2 = argv[2];
	OpenFilesAndReplaceStrings(SearchString, ReplaceString, FileArgument1, FileArgument2);
	return 0;
}
