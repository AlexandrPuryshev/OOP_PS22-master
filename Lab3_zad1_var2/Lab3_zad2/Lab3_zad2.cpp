// Lab3_zad2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Car.h"
#include <iostream>

using namespace std;

struct CarFixture
{
	CCar add;
}CAR;

int main()
{
	int selectOperation = 5;
	while (selectOperation != 0)
	{
		cout << "---------------------------------" << endl;
		cout << "1: Turn on engine" << endl
			<< "2: Turn off engine" << endl
			<< "3: select a gear" << endl
			<< "4: select a speed" << endl
			<< "5: print a information" << endl
			<< "for exit: press key 0" << endl;
		cout << "Choose the operation: ";
		if (cin >> selectOperation)
		{
			cout << "---------------------------------" << endl;
			switch (selectOperation)
			{
			case 1: { CAR.add.TurnOnEngine(); break; }
			case 2: { CAR.add.TurnOffEngine(); break; }
			case 3:
			{
					  int numberOfGear;
					  cout << "select a number of gear: ";
					  cin >> numberOfGear;
					  cout << endl;
					  CAR.add.SetGear(numberOfGear);
					  break;
			}
			case 4:
			{
					  int valueOfSpeed;
					  cout << "select a value of speed: ";
					  cin >> valueOfSpeed;
					  cout << endl;
					  CAR.add.SetSpeed(valueOfSpeed);
					  break;
			}
			case 5: { CAR.add.Info(); break; }
			}
		}
		else
			break;
	}
	return 0;
}

