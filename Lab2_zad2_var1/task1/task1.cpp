// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringProcessor.h"
using namespace std;

bool CheckEmptyLine(const string str)
{
	if (str.empty())
	{
		cout << "string is empty!" << endl;
		return false;
	}
	else
		return true;
}

int main(int argc, char* argv[])
{
	string str = "Yeeeeahhh meeenn            i told     yoou itt???.. !1!    !!!!";
	if (CheckEmptyLine(str))
	{
		cout << RemoveExtraSpacesInString(str);
		return 0;
	}
	else
		return 0;
}
