#include "Point.h"
#include "Node.h"
#include "Stack.h"
#include "MainHeader.h"

void Stack::Push(Point point)
{
	Node *NewNode = new Node(point, nullptr);
	AllocationTest(NewNode);
	NewNode->m_next = m_head;
	m_head = NewNode;
}

void Stack::MakeEmpty()
{
	Node* next = m_head;
	Node* curr = nullptr;
	while (next != nullptr) {
		curr = next;
		next = next->m_next;
		delete curr;
	}
}

void Stack::VoidPop()
{
	Node* n1 = m_head;
	if (m_head != nullptr)
	{
		m_head = m_head->m_next;
		delete n1;
	}
	else
		return;
}

Point Stack::Pop()
{
	Node* n1 = m_head;
	Point p1 = m_head->m_point;
	m_head = m_head->m_next;
	delete n1;
	return p1;
}

Point Stack::Top()
{
	return m_head->m_point;
}

bool Stack::isEmpty()
{
	if (m_head == nullptr)
		return true;
	return false;
}

void Stack::InitStack()
{
	Point p1(1, 1);
	Push(p1);
}


void Stack::AddToTail(Point point)
{
	Node *NewNode = new Node(point, nullptr);
	AllocationTest(NewNode);
	m_tail->m_next = NewNode;
	NewNode->m_next = nullptr;
	m_tail = NewNode;
}

void Stack::setHead(Node * head)
{
	m_head = head;
}

void Stack::setTail(Node * tail)
{
	m_tail = tail;
}

Node* Stack::getHead()
{
	return m_head;
}

Node * Stack::getTail()
{
	return m_tail;
}

Stack::Stack(Node * head, Node * tail)
{
	setHead(head);
	setTail(tail);
}

Stack::~Stack()
{
	MakeEmpty();
}
