#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;


void ReplaceString(ifstream &fIn, ofstream &fOut, string sSearchString, string sReplaceString, bool bFlag)
{
	int count = 0;
	while (!fIn.eof() && sSearchString.length() > 0) //���� ������, ���� �� ����� �����
	{
		string sReplacerString;
		fIn >> sReplacerString;
		char chSymbolTrancsfer = fIn.get();
		if (sReplacerString == sSearchString) // ���� ������ ������� ���� �������
		{
			bFlag = true; // ���� ����� ���������� ���������
			sReplacerString = sReplaceString; // ��������
			count++; // ������� ��� ������ ��������� ����, ��������...
		}
		if (chSymbolTrancsfer != EOF)
		{
			sReplacerString = sReplacerString + chSymbolTrancsfer; // ������� �������� � �������
		}
		fOut << sReplacerString;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc != 5)
	{
		cout << "�������� ������ �����!" << endl;
		return 0;
	}
	string sSearchString, sReplaceString;
	sSearchString = (const char*)argv[3];
	sReplaceString = (const char*)argv[4];

	if ((strlen(argv[1]) > 0) && (strlen(argv[2]) > 0))
	{
		bool bFlag = false;
		ifstream fIn(argv[1]);
		ofstream fOut(argv[2]);
		if ((fIn.is_open() == false) && (!fOut.is_open() == false)) // �������� �� �������� �����
		{
			cout << "������ ��� �������� ������ ������ ��� ������ " << endl;
			return 0;
		}
		else
		{
			ReplaceString(fIn, fOut, sSearchString, sReplaceString, bFlag);
		}
		if (bFlag == false)
		{
			cout << "����� ������ ���!" << endl;
			return 0;
		}
		else
		{
			cout << "�������� ���������\n";
		}
		fOut.close();
		fIn.close();
		getchar();
		return 0;
	}
	else
	{
		cout << "����� ������ ���!" << endl;
		return 0;
	}
	return 0;
}
