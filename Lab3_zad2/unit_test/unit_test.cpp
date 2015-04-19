// unit_test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab3_zad2/Rectangle.h"


struct CRectangleFixture
{
	CRectangle rec1;
	CRectangleFixture() :rec1(0, 0, 3, 6){}
};


BOOST_FIXTURE_TEST_SUITE(Rectangle, CRectangleFixture)

BOOST_AUTO_TEST_CASE(MoveRectangle)
{

	BOOST_CHECK(rec1.GetTop() == 0);
	BOOST_CHECK(rec1.GetLeft() == 0);
	rec1.Move(1, 2);
	BOOST_CHECK(rec1.GetLeft() == 1);
	BOOST_CHECK(rec1.GetTop() == 2);
	BOOST_CHECK(rec1.GetRight() == 1 + 3);
	BOOST_CHECK(rec1.GetBottom() == 2 + 6);
	BOOST_CHECK(rec1.GetArea() == 18);
	BOOST_CHECK(rec1.GetPerimeter() == 18);
}

BOOST_AUTO_TEST_CASE(SizeOfRectangleAndMoveRectangle)
{
	BOOST_CHECK(rec1.GetWidth() == 3);
	BOOST_CHECK(rec1.GetHeight() == 6);
	rec1.Scale(1, 2);
	BOOST_CHECK(rec1.GetWidth() == 3); // 3 * 1
	BOOST_CHECK(rec1.GetHeight() == 12); // 2 * 6
	rec1.Move(2, 4);
	BOOST_CHECK(rec1.GetWidth() == 3);
	BOOST_CHECK(rec1.GetHeight() == 12);
}

BOOST_AUTO_TEST_CASE(RectangleOverlapsWithOther)
{
	CRectangle rec2(2, 4, 3, 4);
	BOOST_CHECK(rec1.Intersect(rec2));
	BOOST_CHECK(rec1.GetLeft() == 2);// m_left = maxLeft;
	BOOST_CHECK(rec1.GetTop() == 0); //	m_top = maxTop;
	BOOST_CHECK(rec1.GetRight() == 5);
	BOOST_CHECK(rec1.GetBottom() == 6);
	BOOST_CHECK(rec1.GetWidth() == 3);	//m_width = maxRight - maxLeft;
	BOOST_CHECK(rec1.GetHeight() == 6); //m_height = maxBottom - maxTop;
	CRectangle rec3(8, 8, 3, 4);
	BOOST_CHECK(!rec1.Intersect(rec3));
	BOOST_CHECK(rec1.GetWidth() == 0);
	BOOST_CHECK(rec1.GetHeight() == 0);
}

BOOST_AUTO_TEST_CASE(RectangleInitWithNegativeoOdds)
{
	CRectangle rec2(2, 4, -3, -4);
	BOOST_CHECK(rec2.GetLeft() == 2);
	BOOST_CHECK(rec2.GetTop() == 4);
	BOOST_CHECK(rec2.GetWidth() == 0);
	BOOST_CHECK(rec2.GetHeight() == 0);
	CRectangle rec3(-2, -4, -3, -4);
	BOOST_CHECK(rec3.GetLeft() == -2);
	BOOST_CHECK(rec3.GetTop() == -4);
	BOOST_CHECK(rec3.GetWidth() == 0);
	BOOST_CHECK(rec3.GetHeight() == 0);
}

BOOST_AUTO_TEST_SUITE_END()