#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

class Point;
class Node;

class Stack
{
public:
	void Push(Point point);
	void MakeEmpty();
	void VoidPop();
	Point Pop();
	Point Top();
	bool isEmpty();
	void InitStack();

	void AddToTail(Point point);

	void setHead(Node *head);
	void setTail(Node *tail);

	Node* getHead();
	Node* getTail();

	Stack(Node *head = nullptr, Node *tail = nullptr);
	~Stack();
private:
	Node* m_head;
	Node* m_tail;
};
#endif // !__LINKEDLIST_H
