// Lab2_zad2_var1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Functions.h"

using namespace std;

void CheckEmptyLine(string str)
{
	if (str == "")
	{
		cout << "string is empty!" << endl;
		exit(-1);
	}
}

int main(int argc, char* argv[])
{

	string S = "Yeeeeahhh meeenn            i told     yoou itt???.. !1!    !!!!";
	CheckEmptyLine(S);
	std::cout << RemoveExtraSpaces(S);
	return 0;
}

