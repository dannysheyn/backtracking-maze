#include "Point.h"
#include "Node.h"

void Node::InsertAfter(Node * newnode)
{
	Node *temp = this->m_next;
	this->m_next = newnode;
	newnode->m_next = temp;
}

Node::Node(Point point, Node * next) : m_point(point)
{
	this->m_next = next;
}


Node::~Node()
{
}
