// TV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "TVSet.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CTVSet tv;
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
			case 1: { tv.TurnOn(); break; }
			case 2: { tv.TurnOff(); break; }
			case 3:
			{
					  int numberOfChannel;
					  cout << "select a number channel: ";
					  cin >> numberOfChannel;
					  cout << endl;
					  tv.SelectChannel(numberOfChannel);
					  break;
			}
			case 4: { tv.Info(); break; }
		}
	}
	return 0;
}

