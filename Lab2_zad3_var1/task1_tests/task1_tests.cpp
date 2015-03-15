// task1_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab2_zad3_var1/Functions.h"

using namespace std;

BOOST_AUTO_TEST_CASE(SomeDiffetentWords)
{
	string str = "asdasd helllloo woord";
	map <string, int> MassOfWord = FindOfftenWord(str);
	BOOST_CHECK(MassOfWord["asdasd"] == 1);
}

BOOST_AUTO_TEST_CASE(SomeTwoEqualtWords1)
{
	string str = "asdasd helllloo helllloo";	
	map<string, int> MassOfWord = FindOfftenWord(str);
	BOOST_CHECK(MassOfWord["helllloo"] == 2);
}

BOOST_AUTO_TEST_CASE(SomeThreeEqualtWords1)
{
	string str = "asdasd helllloo helllloo helllloo";
	map<string, int> MassOfWord = FindOfftenWord(str);
	BOOST_CHECK(MassOfWord["helllloo"] == 3);
}

BOOST_AUTO_TEST_CASE(SomeThreeEqualtWords2)
{
	string str = "asdasd asdasd asdasd helllloo";
	map<string, int> MassOfWord = FindOfftenWord(str);
	BOOST_CHECK(MassOfWord["asdasd"] == 3);
}

BOOST_AUTO_TEST_CASE(SomeTwoEqualtWords2)
{
	string str = "asdasd asdasd helllloo";
	map<string, int> MassOfWord = FindOfftenWord(str);
	BOOST_CHECK(MassOfWord["asdasd"] == 2);
}