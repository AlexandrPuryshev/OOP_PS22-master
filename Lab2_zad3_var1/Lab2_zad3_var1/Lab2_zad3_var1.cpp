// Lab2_zad3_var1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Functions.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string str = "Hello i am you friend and you support. Do you have any friend?";
	map<string, int> MassOfWord = FindOfftenWord(str);
	cout << ShowDictionary(MassOfWord);
}

