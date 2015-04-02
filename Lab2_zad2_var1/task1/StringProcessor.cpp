#include "stdafx.h"
#include "StringProcessor.h"
#include <sstream>

string RemoveExtraSpacesInString(std::string const& arg)
{
	string argEditString = arg;
	istringstream inputStreamStr(argEditString);
	ostringstream outputStreamStr;
	copy(istream_iterator<string>(inputStreamStr), istream_iterator<string>(), ostream_iterator<string>(outputStreamStr, " "));
	argEditString.swap(outputStreamStr.str());
	if (!argEditString.empty())
	{
		argEditString.resize(argEditString.size() - 1);
	}
	return argEditString;
}
//string str = arg;
//string str2;
//for (int i = str.length(); i > 0; --i)
//{
//	if (isMySpace(str[i]))
//	{
//		str.erase(i, 1);
//	}
//}
//return str2;

//string str = arg;
//size_t pos = str.find_last_not_of(" \t");
//if (pos != str.npos)
//{
//	str.erase(pos + 1, str.length());
//	str.erase(0, str.find_first_not_of(" \t"));
//}
//else
//{
//	str.erase();
//}
//for (int i = str.length(); i > 0; --i)
//{
//	if ((str[i] == ' ') && (str[i - 1] == ' '))
//		str.erase(i, 1);
//}
//return str;