#include "stdafx.h"
#include "Functions.h"

map <string, int> FindOfftenWord(string const &line)
{
	size_t count = 0;
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