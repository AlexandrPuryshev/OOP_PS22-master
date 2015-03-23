// TV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TVSet.h"

struct TVSetFixture
{
	CTVSet add;
}TV;


int _tmain(int argc, _TCHAR* argv[])
{
	TV.add.Info();
	TV.add.TurnOn();
	if (TV.add.IsTurnedOn() == true)
	{
		TV.add.SelectChannel(2);
	}
	TV.add.Info();
	if (TV.add.IsTurnedOn() == true)
	{
		TV.add.TurnOff();
	}
	TV.add.Info();
	return 0;
}

