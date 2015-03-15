#include "stdafx.h"
#include "Functions.h"

map <string, int> FindOfftenWord(string const &line)
{
	int count = 0;
	int symbol;
	string word = "";
	map<string, int> Dictionary;
	do
	{
		symbol = line[count];
		if ((symbol < 65 || symbol > 122) || (symbol > 90 && symbol < 97))
		{
			if (!word.empty())
			{
				map <string, int>::iterator it = Dictionary.find(word);
				if (it != Dictionary.end())
				{
					Dictionary[word]++;
				}
				else
				{
					Dictionary[word] = 1;
				}
			}
			word.clear();
		}
		else
		{
			word = word + line[count];
		}
		count++;
	} while (count <= line.size());
	return Dictionary;
}
char* ShowDictionary(map <string, int> Dictionary)
{
	int Value = 0;
	string Key;
	char* Result;
	map<string, int>::iterator it;
	map<string, int>::iterator itEnd = Dictionary.end();

	it = Dictionary.begin();

	while (it != itEnd)
	{
		if (Value < (*it).second)
		{
			Value = (*it).second;
			Key = (*it).first;
		}
		++it;
	}
	Result = new char[Key.length() + 1];
	strcpy(Result, Key.c_str());
	return Result;
}
