#ifndef __POINT_H
#define __POINT_H

class Point
{
public:
	bool AtFinishLine(int rows, int cols);
	Point OneRight();
	Point OneLeft();
	Point OneUp();
	Point OneDown();

	Point PointRight();
	Point PointLeft();
	Point PointDown();
	Point PointUp();
	void InitPoint(int row, int col);

	int getRow();
	int getCol();

	void setRow(int row);
	void setCol(int col);
	
	Point operator-(const Point& other) const;
	Point() = default;
	Point(int row, int col);
	~Point();

	int m_row;
	int m_col;
};
#endif // !__POINT_H
