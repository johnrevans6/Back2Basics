/*John R. Evans
  Created: 03 June 2014
  Modified: 03 June 2014
  Completed In: 45 minutes
  Description: Example of a Singly Linked List*/

#include<iostream>
#include "SinglyLinkedList.h"
using namespace std;


int main()
{
	SinglyLinkedList list;

	//Construct the list
	for (int i = 0; i <= 1000; i+=100)
	{
		list.Append(i);
	}

	
	//Print the list
	
	list.Print();
	

	//Delete an item from the list

	list.Delete(500);
	list.Print();

	system("pause");

	return 0;
}