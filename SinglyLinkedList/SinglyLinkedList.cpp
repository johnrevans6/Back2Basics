#include<iostream>
#include "SinglyLinkedList.h"

using namespace std;

SinglyLinkedList::SinglyLinkedList()
{
	head = NULL;
}

SinglyLinkedList::~SinglyLinkedList()
{
	Node* doomed = head;

	while (doomed != NULL)
	{
		Node* temp = doomed->GetNext();
		delete doomed;
		doomed = temp;
	}
	head = NULL;
}


int SinglyLinkedList::SizeOf()
{
	Node* temp = head;
	
	int count=0;

	while (temp->GetNext() != NULL)
	{
		count++;
		temp = temp->GetNext();
	}

	
	return count;

}

void SinglyLinkedList::Append(int data)
{
	//Create a new node
	Node* node = new Node();

	node->SetData(data);
	node->SetNext(NULL);

	//temp pointer
	Node* temp = head;

	//First Case: List isn't empty
	//Add to end of list
	if (temp != NULL)
	{
		while (temp->GetNext() != NULL)
		{
			temp = temp->GetNext();
		}

		temp->SetNext(node);
	}
	else
	{
		//List is empty
		head = node;
	}

}

void SinglyLinkedList::Delete(int data)
{
	//Temp pointer for node to delete
	Node* doomed = head;

	
	//First Case: List is empty
	//Do nothing
	if (doomed == NULL)
	{
		return;
	}

	//Second Case: Only one item in the list
	//Delete the node, then set the head to NULL

	if (doomed->GetNext() == NULL && doomed->Getdata()==data)
	{
		delete doomed;
		head = NULL;
	}
	else
	{
		//Third Case: More than one item in the list

		Node* temp=doomed;

		while (doomed != NULL)
		{
			//Item found 
			if (doomed->Getdata() == data)
			{
				break;
			}

			//Set the current node as the doomed node
			temp = doomed;

			//Point to the next node
			doomed = doomed->GetNext();
		}

		//Point previous node to the node in front of the node to be deleted
		if (temp->Getdata() == data)
		{

			temp->SetNext(doomed->GetNext());

			//Delete the node
			delete doomed;
		}
		else
		{
			cout << "NO SUCH ITEM" << endl;
			return;
		}
	}
}

void SinglyLinkedList::Print()
{
	Node* temp = head;

	//List is empty
	if (temp == NULL)
	{
		cout << "Empty list" << endl;
		return;
	}

	//One item in list
	if (temp->GetNext() == NULL)
	{
		cout << temp->Getdata() << endl;
		return;
	}

	//List has more than one item in it
	while (temp != NULL)
	{
		cout << temp->Getdata()<<" ";
		temp=temp->GetNext();
	}

	cout << endl<<endl;
}