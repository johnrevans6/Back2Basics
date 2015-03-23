/*This program demonstrates the basic binary tree traversals (both recursive and iterative versions). As a review, the traversals are:
Preorder - Visit the root, Traverse left subtree, Traverse right subtree
Inorder - Traverse left subtree, Visit the root, Traverse right subtree
Postorder - Traverse left subtree, Traverse right subtree, Visit the root*/

#include "binarytree.h"
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	BinaryTree tree;

	srand(time(NULL));

	//Build the tree using a random ordering of 10 integers between 1 and 10
	for (int i = 1; i <= 10; i++)
	{
		int key = rand() % 10 + 1;
		if (tree.search(key) == NULL)
		{
			tree.insert(key);
		}
		else
		{
			i--;
		}
	}	

	cout << "Preorder traversal Recursive:"<<endl;
	tree.preorderTraversalrec(tree.getRoot());

	cout << endl << endl;

	cout << "Preorder traversal Iterative:" << endl;
	tree.preorderTraversalit(tree.getRoot());

	cout << endl << endl;
	
	cout << "Inorder traversal Recursive:" << endl;
	tree.inorderTraversalrec(tree.getRoot());

	cout << endl << endl;

	cout << "Inorder traversal Iterative:" << endl;
	tree.inorderTraversalit(tree.getRoot());

	cout << endl << endl;

	cout << "Postorder traversal Recursive:" << endl;
	tree.postorderTraversalrec(tree.getRoot());

	cout << endl << endl;

	cout << "Postorder traversal Iterative:" << endl;
	tree.postorderTraversalit(tree.getRoot());

	cout << endl << endl;
	return 0;
}
