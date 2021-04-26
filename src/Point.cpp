#include "Point.h"

bool Point::AtFinishLine(int rows, int cols)
{
	if ((this->m_row == rows - 2) && (this->m_col == cols - 1))
		return true;
	return false;
}

Point Point::OneRight()
{
	Point Right(*this);
	Right.m_col += 1;
	return Right;
}

Point Point::OneLeft()
{
	Point Left(*this);
	Left.m_col -= 1;
	return Left;
}

Point Point::OneUp()
{
	Point Up(*this);
	Up.m_row -= 1;
	return Up;
}

Point Point::OneDown()
{
	Point Down(*this);
	Down.m_row += 1;
	return Down;
}

Point Point::PointRight()
{
	Point Right(*this);
	Right.m_row += 2;
	return Right;
}

Point Point::PointLeft()
{
	Point Left(*this);
	Left.m_row -= 2;
	return Left;
}

Point Point::PointDown()
{
	Point Down(*this);
	Down.m_col -= 2;
	return Down;
}

Point Point::PointUp()
{
	Point Up(*this);
	Up.m_col += 2;
	return Up;
}

void Point::InitPoint(int row, int col)
{
	setRow(row);
	setCol(col);
}

int Point::getRow()
{
	return m_row;
}

int Point::getCol()
{
	return m_col;
}

void Point::setRow(int row)
{
	m_row = row;
}

void Point::setCol(int col)
{
	m_col = col;
}

Point Point::operator-(const Point & other) const
{
	return Point(m_row - other.m_row, m_row - other.m_col);
}

Point::Point(int row, int col)
{
	m_row = row;
	m_col = col;
}

Point::~Point()
{
}
