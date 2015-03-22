#include "binarytree.h"
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	BinaryTree tree;

	srand(time(NULL));

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

	cout << "Preorder traversal:"<<endl;
	tree.preorderTraversalrec(tree.getRoot());
	
	cout << endl << endl;
	
	cout << "Inorder traversal:" << endl;
	tree.inorderTraversalrec(tree.getRoot());

	cout << endl << endl;

	cout << "Postorder traversal:" << endl;
	tree.postorderTraversalrec(tree.getRoot());
	return 0;
}
