// ForReplaceLab1_OOP.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <assert.h>

using namespace std;

bool ReplaceStringInFile(ifstream &fIn, ofstream &fOut, const string &searchString, const string &replaceString)
{
	bool stringIsFound = false;
	string strintFromFile;
	getline(fIn, strintFromFile);
	size_t positionInString = 0;
	while ((positionInString = strintFromFile.find(searchString, positionInString)) != strintFromFile.npos)
	{
		strintFromFile.replace(positionInString, searchString.length(), replaceString);
		positionInString += replaceString.length();
		stringIsFound = true;
	}
	fOut << strintFromFile;
	return stringIsFound;
}

bool OpenFilesAndReplaceStrings(const string &searchString, const string &replaceString, char* pcharFileArgument1, char* pcharFileArgument2)
{
	if ((pcharFileArgument1[0] != 0) && (pcharFileArgument2[0] != 0))
	{
		ifstream fIn;
		fIn.open((const char*)pcharFileArgument1, ios::in);
		if (fIn.fail()) // check opening of the file
		{
			cout << "Error when opening files of reading" << endl;
			return true;
		}
		else
		{
			ofstream fOut;
			fOut.open((const char*)pcharFileArgument2, ios::out);
			if (fOut.fail())
			{
				cout << "Error when opening files of writing" << endl;
				return true;
			}
			if (!ReplaceStringInFile(fIn, fOut, searchString, replaceString))
			{
				cout << "Such line isn't present!" << endl;
				return true;
			}
			else
			{
				cout << "Action is executed" << endl;
				return true;
			}
		}
	}
	return false;
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
	string searchString, replaceString;
	searchString = (const char*)argv[1];
	replaceString = (const char*)argv[2];
	char* pcharFileArgument1Input = argv[3];
	char* pcharFileArgument2Output = argv[4];
	if (OpenFilesAndReplaceStrings(searchString, replaceString, pcharFileArgument1Input, pcharFileArgument2Output))
	{
		return 0;
	}
	else
	{
		cout << "Error when opening files" << endl;
		return 0;
	}
}
