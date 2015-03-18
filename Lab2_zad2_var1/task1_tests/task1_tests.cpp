// task1_tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/StringProcessor.h"

using namespace std;

//BOOST_WARN_MESSAGE(условие, сообщение) – выводит предупреждение с текстом сообщения, если условие ложно;

BOOST_AUTO_TEST_CASE(MultiplySpaces)
{
	string Spaces = "         ";
	RemoveExtraSpaces(Spaces);
	BOOST_WARN_MESSAGE(Spaces == "        ", "RemoveExtraSpaces dont delete MultiplySpaces!");
}

BOOST_AUTO_TEST_CASE(MultiplySpacesBeforeString)
{
	string Spaces = "       Natasha";
	RemoveExtraSpaces(Spaces);
	BOOST_WARN_MESSAGE(Spaces == "Natasha", "RemoveExtraSpaces dont delete MultiplySpacesBeforeString!");
}

BOOST_AUTO_TEST_CASE(MultiplySpacesAfterString)
{
	string Spaces = "Natasha        ";
	RemoveExtraSpaces(Spaces);
	BOOST_WARN_MESSAGE(Spaces == "Natasha", "RemoveExtraSpaces dont delete MultiplySpacesAfterString!");
}

BOOST_AUTO_TEST_CASE(MultiplySpacesInString)
{
	string Spaces = "Natasha    !@#!    a";
	RemoveExtraSpaces(Spaces);
	BOOST_WARN_MESSAGE(Spaces == "Natasha !@#! a", "RemoveExtraSpaces dont delete MultiplySpacesInString!");
}

BOOST_AUTO_TEST_CASE(OneSpace)
{
	string Spaces = " ";
	RemoveExtraSpaces(Spaces);
	BOOST_WARN_MESSAGE(Spaces == "", "RemoveExtraSpaces dont delete OneSpace!");
}