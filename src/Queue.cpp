#include "Point.h"
#include "Queue.h"
#include "MainHeader.h"



bool Queue::IsInMaze(int p_row, int p_col, int rows, int cols)
{
	if (p_row <= rows - 1 && p_row >= 0)
		if (p_col <= cols - 1 && p_col >= 0)
			return true;
	return false;
}

void Queue::AddAllNeighbors(Point & point, char** maze, int rows, int cols) 
{
	Point neighbor = point.OneRight();
	if(IsInMaze(neighbor.getRow(), neighbor.getCol() , rows, cols))
		if (maze[neighbor.m_row][neighbor.m_col] == ' ' ) 
			this->EnQueue(neighbor);
	neighbor = point.OneDown();
	if (IsInMaze(neighbor.getRow(), neighbor.getCol(), rows, cols))
		if (maze[neighbor.m_row][neighbor.m_col] == ' ')
			this->EnQueue(neighbor);
	neighbor = point.OneLeft();
	if (IsInMaze(neighbor.getRow(), neighbor.getCol(), rows, cols))
		if (maze[neighbor.m_row][neighbor.m_col] == ' ')
			this->EnQueue(neighbor);
	neighbor = point.OneUp();
	if (IsInMaze(neighbor.getRow(), neighbor.getCol(), rows, cols))
		if (maze[neighbor.m_row][neighbor.m_col] == ' ')
			this->EnQueue(neighbor);
}


Point * Queue::InitArr(int row, int col)
{
	Point *arr = new Point[row*col];
	return arr;
}

bool Queue::IsEmpty()
{
	if ((m_tail + 1) % m_arr_size == m_head) {
		cout << "no solution\n";
		exit(1);
	}
	else
		return false;
}

Point Queue::Front()
{
	if (IsEmpty())
	{
		cout << "QUEUE EMPTY\n";
		exit(1);
	}
	return m_point_arr[m_head];
}

Point Queue::DeQueue()
{
	Point temp = m_point_arr[m_head];
	m_head = AddOne(m_head);
	return temp;
}

void Queue::EnQueue(Point p)
{
	m_tail = AddOne(m_tail);
	m_point_arr[m_tail] = p;
}

int Queue::getHead()
{
	return m_head;
}

int Queue::getTail()
{
	return m_tail;
}

Point * Queue::getPointArr() const
{
	return m_point_arr;
}

int Queue::getArrSize()
{
	return m_arr_size;
}

void Queue::setHead(int head)
{
	m_head = head;
}

void Queue::setTail(int tail)
{
	m_tail = tail;
}

void Queue::setPointArr(Point * arr)
{
	m_point_arr = arr;
}

void Queue::setSizeArr(int size)
{
	m_arr_size = size;
}

Queue::Queue(int row, int col)
{
	m_point_arr = InitArr(row, col);
	m_head = 0;
	m_tail = 0;
	m_arr_size = row * col;
}


Queue::~Queue()
{
	delete[] m_point_arr;
}

int Queue::AddOne(int num)
{
	return ((1 + num) % getArrSize());
}

void Queue::InitQueue()
{
	Point p(1, 0);
	m_point_arr[0] = p;
}
