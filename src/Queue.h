#ifndef __QUEUE_H
#define __QUEUE_H

class Point;

class Queue
{
public:
	bool IsInMaze(int p_row,int p_col,int rows, int cols);
	void AddAllNeighbors(Point &point, char** maze, int rows, int cols);
	Point *InitArr(int row, int col);
	bool IsEmpty();
	Point Front();
	Point DeQueue();
	void EnQueue(Point p);
	int AddOne(int num);
	void InitQueue();

	int getHead();
	int getTail();
	Point* getPointArr() const;
	int getArrSize();

	void setHead(int head);
	void setTail(int tail);
	void setPointArr(Point *arr);
	void setSizeArr(int size);
	Queue(int row = 0, int col = 0);
	~Queue();
private:
	int m_head;
	int m_tail;
	Point* m_point_arr;
	int m_arr_size;
};
#endif // !__QUEUE_H
