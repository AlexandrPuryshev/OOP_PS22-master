// Lab2_zad3_var1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Functions.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string str = "  ";
	map<string, int> MassOfWord = FindOfftenWord(str);
	cout << ShowDictionary(MassOfWord);
}

