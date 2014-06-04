#ifndef NODE_H
#define NODE_H

class Node
{
public:

	//Constructor
	Node();

	//Members
	void SetData(int d);
	void SetNext(Node* ptr);
	
	int Getdata();
	Node* GetNext();

private:
	int data;
	Node* next;
};



#endif