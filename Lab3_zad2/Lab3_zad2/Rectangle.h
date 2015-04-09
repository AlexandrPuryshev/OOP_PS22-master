#pragma once
class CRectangle
{
public:
	CRectangle(const int Left, const int Top, const int Width, const int Height);
	~CRectangle();

	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	void Info()const;
	bool Intersect(CRectangle const& other);

private:
	int m_width;
	int m_height;
	int m_left;
	int m_top;
	int m_right;
	int m_bottom;
	int m_area;
	int m_perimetr;
};

