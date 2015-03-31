// TV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "TVSet.h"

struct TVSetFixture
{
	CTVSet add;
}TV;

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int selectOperation = 5;
	while (selectOperation != 0)
	{
		cout << "---------------------------------" << endl;
		cout << "1: Turn on the TV" << endl
			<< "2: Turn off the TV" << endl
			<< "3: select a channel" << endl
			<< "4: print a information" << endl
			<< "for exit: press key 0" << endl;
		cout << "Choose the operation: ";
		cin >> selectOperation;
		cout << "---------------------------------" << endl;
		switch (selectOperation)
		{
			case 1: { TV.add.TurnOn(); break; }
			case 2: { TV.add.TurnOff(); break; }
			case 3:
			{
					  int numberOfChannel;
					  cout << "select a number channel: ";
					  cin >> numberOfChannel;
					  cout << endl;
					  TV.add.SelectChannel(numberOfChannel);
					  break;
			}
			case 4: { TV.add.Info(); break; }
		}
	}
	return 0;
}

