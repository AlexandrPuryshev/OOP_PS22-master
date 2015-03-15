// task1_test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab2_zad2_var1/Functions.h"

BOOST_AUTO_TEST_CASE(MultiplySpaces)
{
	string Spaces = "         ";
	RemoveExtraSpaces(Spaces);
	BOOST_WARN_MESSAGE(Spaces == "", "RemoveExtraSpaces dont delete MultiplySpaces!");
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