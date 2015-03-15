// Lab2_zad2_var1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Functions.h"

using namespace std;

string RemoveExtraSpaces(std::string const& arg)
{
	string str = arg;
	size_t pos = str.find_last_not_of(" \t");
	if (pos != str.npos)		
	{
		str.erase(pos + 1, str.length());
		str.erase(0, str.find_first_not_of(" \t"));
	}
	else
	{
		str.erase();
	}
	for (int i = str.length(); i > 0; --i)
	{
		if ((str[i] == ' ') && (str[i - 1] == ' '))
			str.erase(i, 1);
	}
	return str;
}

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

