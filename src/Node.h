#ifndef  __NODE_H
#define  __NODE_H

class Point;

class Node
{
public:
	void InsertAfter(Node *newnode);
	Node(Point point, Node *next = nullptr);
	~Node();

	Point m_point;
	Node *m_next;
};
#endif //  __NODE_H
