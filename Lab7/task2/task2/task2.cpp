// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyArray.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

int main()
{
	CMyArray<string> strArr;
	for (int i = 0; i < 5; ++i)
	{
		strArr.Add(to_string(i));
	}
	assert(strArr.GetSize() == 5u);
	assert(strArr[4] == "4");
	strArr.Resize(2);
	assert(strArr.GetSize() == 2u);
	assert(strArr[1] == "1");
	cout << strArr[2] << endl;
}