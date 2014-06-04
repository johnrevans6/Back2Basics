#include "Node.h"

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

class SinglyLinkedList :Node
{
public:
	
	//Constructor/Destructor
	SinglyLinkedList();
	~SinglyLinkedList();
	
	//Get the size of the list
	int SizeOf();
	
	//Add to the list
	void Append(int data);

	//Delete from the list
	void Delete(int data);

	//Print the list
	void Print();

private:
	Node *head;
};




#endif