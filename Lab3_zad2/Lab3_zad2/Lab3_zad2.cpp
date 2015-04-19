// Lab3_zad2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iosfwd>
#include <sstream>

using namespace std;

size_t switchFunc(string buf, string* protoCommands)
{
	for (size_t i = 0; i < 3; ++i)
	{
		if (buf == protoCommands[i])
		{
			return i;
		}
	}
	return -1;
}

void ApplyCommands(ifstream &file, CRectangle &rec, vector<CRectangle> &recs)
{
	bool isNewLine = false;
	string line;
	string commands[3]
	{
		"Move",
		"Scale",
		"Rectangle",
	};

	while (getline(file, line))
	{
		stringstream stringStream;
		stringStream << line;
		string commandInLine;
		int left, top, width, height;
		int dx, dy;
		int sx, sy;
		stringStream >> commandInLine;
		if (line.find('\n') == std::string::npos)
		{
			isNewLine = true;
			switch (switchFunc(commandInLine, commands))
			{
			case 0:
			{
				if (stringStream >> dx >> dy)
				{
					rec.Move(dx, dy);
					break;
				}
			}
			case 1:
			{
				if (stringStream >> sx >> sy)
				{
					rec.Scale(sx, sy);
					break;
				}
			}
			case 2:
			{
				if (stringStream >> left >> top >> width >> height)
				{
					CRectangle rect(left, top, width, height);
					rec = rect;
					break;
				}

			}
			
			}

		}
	}
	if (rec.GetWidth() != 0 && rec.GetHeight() != 0 && isNewLine)
	{
		recs.push_back(rec);
	}
}


bool PrintResults(vector<CRectangle> &recs, _TCHAR* argv[])
{
	ofstream outputFile(argv[3]);
	if (!(outputFile.is_open()))
	{
		cout << "Error of write output file" << endl;
		return 0;
	}
	if (recs.size() != 0)
	{
		CRectangle intersectRec;
		for (size_t i = 0; i < recs.size(); i+=2)
		{
			intersectRec = recs[i];
			intersectRec.Intersect(recs[i+1]);
			outputFile << "Rectangle " << i + 1 << ":" << endl;
			recs[i].PrintInFileInfo(outputFile);
			outputFile << "Rectangle " << i + 2 << ":" << endl;
			recs[i + 1].PrintInFileInfo(outputFile);
		}
		outputFile << "Intersection rectangle:" << endl;
		intersectRec.PrintInFileInfo(outputFile);
		return true;
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int PARAMS_COUNT = 4;
	if (argc != PARAMS_COUNT)
	{
		cout << "Error of number arguments!" << endl;
		return 0;
	}
	CRectangle rectang;
	vector<CRectangle> recs;
	ifstream inputFile1(argv[1]);
	ifstream inputFile2(argv[2]);
	if (!(inputFile1.is_open()))
	{
		cout << "Error of read file1" << endl;
		return 0;
	}
	if (!(inputFile2.is_open()))
	{
		cout << "Error of read file2" << endl;
		return 0;
	}
	CRectangle rec1;
	CRectangle rec2;
	ApplyCommands(inputFile1, rec1, recs);
	ApplyCommands(inputFile2, rec2, recs);
	if (!PrintResults(recs, argv)) //? output 'o'
	{
		return 0;
	}
	getchar();
	return 0;
}
