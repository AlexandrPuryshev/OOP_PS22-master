#include "stdafx.h"
#include <iostream>
#include "Rectangle.h"

using namespace std;

CRectangle::CRectangle(const int Left, const int Top, const int Width, const int Height)
	:m_left(0),
	m_top(0),
	m_width(0),
	m_height(0)		
{
	if (m_width < 0 && m_height < 0)
	{

	}
}


CRectangle::~CRectangle()
{
}

void CRectangle::Move(int dx, int dy)
{
	m_left = m_left + dx;
	m_top = m_top + dy;
	m_right = m_left + m_width;
	m_bottom = m_top + m_height;
}

void CRectangle::Scale(int sx, int sy)
{
	if (sx > 0 && sy > 0)
	{
		m_width = m_width * sx;
		m_height = m_height * sy;
		m_right = m_left + m_width;
		m_bottom = m_top + m_height;
		m_area = m_height * m_width;
		m_perimetr = 2 * (m_height + m_width);
	}
}

void CRectangle::Info() const
{
	cout << "Left Top: " << m_left << ";" << m_top << endl;
	cout << "Size: " << m_width << "*" << m_height << endl;
	cout << "Right bottom: " << m_right << ";" << m_bottom << endl;
	cout << "Area: " << m_area << endl;
	cout << "Perimetr: " << m_perimetr << endl;
}