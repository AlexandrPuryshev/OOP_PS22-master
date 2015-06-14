// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include "../task2/MyArray.h"

using namespace std;


BOOST_AUTO_TEST_CASE(CreateEmptyMyArray)
{
	const CMyArray<string> arr;
	BOOST_CHECK(arr.GetSize() == 0);
	BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
	BOOST_CHECK_THROW(arr[0], out_of_range);
	CMyArray<string> arr2;
	BOOST_CHECK_THROW(arr2[0], out_of_range);
	CMyArray<double> nums;
	BOOST_CHECK(arr.GetSize() == 0);
	BOOST_CHECK_THROW(nums[0], out_of_range);
}

BOOST_AUTO_TEST_CASE(TestAddMethod)
{	
	{
		CMyArray<int> arr;
		BOOST_CHECK(arr.GetSize() == 0);
		arr.Add(1);
		arr.Add(2);
		BOOST_CHECK(arr.GetSize() == 2);
		BOOST_CHECK(arr[0] == 1);
		BOOST_CHECK(arr[1] == 2);
	}
	
	{
		CMyArray<string> arr;;
		arr.Add("World is Great!");
		arr.Add("Oh realy?!");
		BOOST_CHECK(arr.GetSize() == 2);
		BOOST_CHECK(arr[0] == "World is Great!");
		BOOST_CHECK(arr[1] == "Oh realy?!");
	}

	{
		CMyArray<double> arr;
		arr.Add(2.123);
		BOOST_CHECK(arr.GetSize() == 1);
		BOOST_CHECK(arr[0] == 2.123);
	}

}

BOOST_AUTO_TEST_CASE(TestResizeMethod)
{
	CMyArray<size_t> massSize_t;
	for (size_t count = 0; count < 10; ++count)
	{
		massSize_t.Add(count);
	}
	BOOST_CHECK(massSize_t.GetSize() == 10);
	BOOST_CHECK(massSize_t[8] == 8);
	massSize_t.Resize(5);
	BOOST_CHECK(massSize_t.GetSize() == 5);
	BOOST_CHECK(massSize_t[4] == 4);
	BOOST_CHECK_THROW(massSize_t[5], out_of_range);
	BOOST_CHECK_THROW(massSize_t[6], out_of_range);
}

BOOST_AUTO_TEST_CASE(TestClearMethod)
{
	CMyArray<string> massString;
	massString.Add("World is Great!");
	massString.Add("Oh realy?!");
	BOOST_CHECK(massString.GetSize() == 2);
	massString.Clear();
	BOOST_CHECK(massString.GetSize() == 0);
	BOOST_CHECK_THROW(massString[1], out_of_range);

}

BOOST_AUTO_TEST_CASE(TestDefaultConstructor)
{
	CMyArray<string> massString;
	massString.Add("World is Great!");
	massString.Add("Oh realy?!");
	CMyArray<string> newMass(massString);
	BOOST_CHECK(newMass.GetSize() == 2);
	BOOST_CHECK(massString.GetSize() == 2);
	BOOST_CHECK(newMass[0] == "World is Great!");
	BOOST_CHECK(massString[1] == "Oh realy?!");
	BOOST_CHECK_THROW(newMass[2], out_of_range);
	BOOST_CHECK_THROW(massString[2], out_of_range);
}

BOOST_AUTO_TEST_CASE(TestOperatorIsEqual)
{

	CMyArray<string> massString;
	massString.Add("World is Great!");
	massString.Add("Oh realy?!");
	CMyArray<string> newMass;
	newMass = massString;
	BOOST_CHECK(newMass.GetSize() == 2);
	BOOST_CHECK(massString.GetSize() == 2);
	BOOST_CHECK(newMass[0] == "World is Great!");
	BOOST_CHECK(massString[1] == "Oh realy?!");
	BOOST_CHECK_THROW(newMass[2], out_of_range);
	BOOST_CHECK_THROW(massString[2], out_of_range);
}