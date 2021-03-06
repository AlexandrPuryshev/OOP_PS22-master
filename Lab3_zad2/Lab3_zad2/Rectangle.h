#pragma once
#include <iostream>
#include <fstream> 

using namespace std;

class CRectangle
{
public:
	CRectangle::CRectangle();
	CRectangle(const int left, const int top, const int width, const int height);
	~CRectangle();

	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	void PrintInFileInfo(ofstream &file) const;
	bool Intersect(CRectangle const& other);

	int GetPerimeter() const;
	int GetRight() const;
	int GetLeft() const;
	int GetTop() const;
	int GetBottom() const;
	int GetArea() const;
	int GetHeight() const;
	int GetWidth() const;

private:
	int m_left;
	int m_top;

	int m_width;
	int m_height;
};

