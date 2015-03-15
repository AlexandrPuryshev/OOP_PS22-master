#include "stdafx.h"
#include "Functions.h"

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
