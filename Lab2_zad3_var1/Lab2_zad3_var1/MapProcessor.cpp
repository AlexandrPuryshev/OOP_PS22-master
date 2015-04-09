#include "stdafx.h"
#include "Functions.h"

map <string, int> FindOfftenWord(string const &line)
{
	size_t count = 0;
	int asciiCodeSymbol;
	string word;
	map<string, int> dictionary;
	do
	{
		asciiCodeSymbol = line[count];
		if ((asciiCodeSymbol < 65 || asciiCodeSymbol > 122) || (asciiCodeSymbol > 90 && asciiCodeSymbol < 97))
		{
			if (!word.empty())
			{
				map <string, int>::iterator it = dictionary.find(word);
				if (it != dictionary.end())
				{
					++dictionary[word];
				}
				else
				{
					dictionary[word] = 1;
				}
			}
			word.clear();
		}
		else
		{
			word.push_back(line[count]);
		}
		count++;
	} while (count <= line.size());
	return dictionary;
}

char* ShowDictionary(map <string, int> dictionary)
{
	int value = 0;
	string key;
	char* result;
	map<string, int>::iterator it;
	map<string, int>::iterator itEnd = dictionary.end();

	it = dictionary.begin();

	while (it != itEnd)
	{
		if (value < (*it).second)
		{
			value = (*it).second;
			key = (*it).first;
		}
		++it;
	}
	result = new char[key.length() + 1];
	strcpy_s(result, key.length() + 1, key.c_str());
	return result;
}
