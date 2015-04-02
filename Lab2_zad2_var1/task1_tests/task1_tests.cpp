// task1_tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/StringProcessor.h"

using namespace std;

BOOST_AUTO_TEST_CASE(MultiplySpaces)
{
	string spacesStr = "         ";
	string resultString;
	resultString = RemoveExtraSpacesInString(spacesStr);
	BOOST_CHECK_MESSAGE(resultString.empty(), "RemoveExtraSpaces dont delete MultiplySpaces!");
}

BOOST_AUTO_TEST_CASE(MultiplySpacesBeforeString)
{
	string spacesStrWithWord = "       Natasha";
	string resultString;
	resultString = RemoveExtraSpacesInString(spacesStrWithWord);
	BOOST_CHECK_MESSAGE(resultString == "Natasha", "RemoveExtraSpaces dont delete MultiplySpacesBeforeString!");
}

BOOST_AUTO_TEST_CASE(MultiplySpacesAfterString)
{
	string spacesStrWithWord = "Natasha        ";
	string resultString;
	resultString = RemoveExtraSpacesInString(spacesStrWithWord);
	BOOST_CHECK_MESSAGE(resultString == "Natasha", "RemoveExtraSpaces dont delete MultiplySpacesAfterString!");
}

BOOST_AUTO_TEST_CASE(MultiplySpacesInString)
{
	string spacesStrWithWord = "Natasha      !@#!     a";
	string resultString;
	resultString = RemoveExtraSpacesInString(spacesStrWithWord);
	BOOST_CHECK_MESSAGE(resultString == "Natasha !@#! a", "RemoveExtraSpaces dont delete MultiplySpacesInString!");
}

BOOST_AUTO_TEST_CASE(OneSpace)
{
	string spaceInStr = " ";
	string resultString;
	resultString = RemoveExtraSpacesInString(spaceInStr);
	BOOST_CHECK_MESSAGE(resultString.empty(), "RemoveExtraSpaces dont delete OneSpace!");
}