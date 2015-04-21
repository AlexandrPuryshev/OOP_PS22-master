#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "Rectangle.h"

using namespace std;

int CRectangle::GetWidth() const
{
	return m_width;
}

int CRectangle::GetHeight() const
{
	return m_height;
}

int CRectangle::GetArea() const
{
	return m_width * m_height;
}

int CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
}

int CRectangle::GetRight() const
{
	return m_left + m_width;
}

int CRectangle::GetBottom() const
{
	return m_top + m_height;
}

CRectangle::CRectangle()
{

}

CRectangle::~CRectangle()
{

}

CRectangle::CRectangle(const int left, const int top, const int width, const int height)
	:m_left(left),
	 m_top(top),
	 m_width(std::max(0, width)),
	 m_height(std::max(0, height))
{
	
}

void CRectangle::Move(int dx, int dy)
{
	m_left = m_left + dx;
	m_top = m_top + dy;
}

void CRectangle::Scale(int sx, int sy)
{
	if (sx > 0 && sy > 0)
	{
		m_width = m_width * sx;
		m_height = m_height * sy;
	}
}

bool CRectangle::Intersect(CRectangle const& other)
{
	if (GetBottom() > other.m_top || m_top < other.GetBottom() || m_left > other.GetRight() || GetRight() < other.m_left)
	{
		m_width = 0;
		m_height = 0;
		return false;
	}
	else
	{
		int m_left = max(m_left, other.m_left);
		int m_top = min(m_top, other.m_top);

		int maxRight = max(GetRight(), other.GetRight());
		int maxBottom = min(GetBottom(), other.GetBottom());

		m_width = maxRight - m_left;
		m_height = maxBottom - m_top;
		return true;
	}
}

void CRectangle::Info() const
{
	cout << "Left Top: " << m_left << ";" << m_top << endl;
	cout << "Size: " << GetWidth() << "*" << GetHeight() << endl;
	cout << "Right bottom: " << GetRight() << ";" << GetBottom() << endl;
	cout << "Area: " << GetArea() << endl;
	cout << "Perimeter: " << GetPerimeter() << endl;
}