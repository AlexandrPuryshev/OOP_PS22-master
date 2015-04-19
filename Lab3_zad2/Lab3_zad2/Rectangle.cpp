#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
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

int CRectangle::GetLeft() const
{
	return m_left;
}

int CRectangle::GetTop() const
{
	return m_top;
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
	if (m_left > other.GetRight() || GetRight() < other.m_left || m_top > other.GetBottom() || GetBottom() < other.m_top)
	{
		m_width = 0;
		m_height = 0;
		return false;
	}
	else
	{
		int maxLeft = max(m_left, other.m_left);
		int maxTop = min(m_top, other.m_top);

		int maxRight = max(GetRight(), other.GetRight());
		int maxBottom = min(GetBottom(), other.GetBottom());

		m_left = maxLeft; 
		m_top = maxTop;
		m_width = maxRight - maxLeft;
		m_height = maxBottom - maxTop;
		return true;
	}
}

void CRectangle::PrintInFileInfo(ofstream &file) const
{
	file << "	Left Top: " << m_left << ";" << m_top << endl;
	file << "	Size: " << GetWidth() << "*" << GetHeight() << endl;
	file << "	Right bottom: " << GetRight() << ";" << GetBottom() << endl;
	file << "	Area: " << GetArea() << endl;
	file << "	Perimeter: " << GetPerimeter() << endl;
	file << endl;
}