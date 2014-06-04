#include "Node.h"

//Blank constructor
Node::Node(){};

void Node::SetData(int d)
{
	data = d;
}

void Node::SetNext(Node* ptr)
{
	next = ptr;
}

int Node::Getdata()
{
	return data;
}

Node* Node::GetNext()
{
	return next;
}

