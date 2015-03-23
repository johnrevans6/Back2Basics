#include "binarytree.h"
#include <stack>
#include <iostream>
using namespace std;


BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	destroyTree();
}

void BinaryTree::destroyTree()
{
	destroyTree(root);
}

void BinaryTree::destroyTree(Node* leaf)
{
	if (leaf != NULL)
	{
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}	
}

void BinaryTree::insert(int k)
{
	if (root != NULL)
	{
		insert(root, k);
	}
	else
	{
		root = new Node();
		root->setKey(k);
		root->left = NULL;
		root->right = NULL;
	}
}

void BinaryTree::insert(Node* leaf, int k)
{

	if (k < leaf->getKey())
	{
		if (leaf->left != NULL)
		{
			insert(leaf->left, k);
		}
		else
		{
			leaf->left = new Node();
			leaf->left->setKey(k);
			leaf->left->left = NULL;//Left child
			leaf->left->right = NULL;//Right child
		}
	}
	else if (k >= leaf->getKey())
	{
		if (leaf->right != NULL)
		{
			insert(leaf->right, k);
		}
		else
		{
			leaf->right = new Node();
			leaf->right->setKey(k);
			leaf->right->right = NULL;//Right child
			leaf->right->left = NULL;//Left child
		}
	}
}

BinaryTree::Node* BinaryTree::search(int k)
{
	return search(root, k);
}

BinaryTree::Node* BinaryTree::search(Node* leaf,int k)
{
	if (leaf != NULL)
	{
		if (k == leaf->getKey())
		{
			return leaf;
		}

		if (k < leaf->getKey())
		{
			return search(leaf->left, k);
		}
		else
		{
			return search(leaf->right, k);
		}
	}

	return NULL;
}

void BinaryTree::inorderTraversalrec(Node* node)
{
	//If node isn't null, then traverse left subtree, followed by the root, followed by the right subtree recursively
	if (node == NULL)
	{
		return;
	}

	inorderTraversalrec(node->left);
	printf("%d ", node->getKey());
	inorderTraversalrec(node->right);
	
}

void BinaryTree::inorderTraversalit(Node* node)
{
	Node* current;
	Node* prev;

	if (node == NULL)
	{
		return;
	}

	current = node;

	while (current != NULL)
	{
		//If the left subtree is null, then print the value of the current node, and traverse to 
		//the right subtree
		if (current->left == NULL)
		{
			printf("%d ", current->getKey());
			current = current->right;
		}
		else
		{
			//Check the left predecessor
			prev = current->left;

			//While the right child of the predecessor isn't equal to null or the current node, traverse the right child
			while (prev->right != NULL && prev->right != current)
			{
				prev = prev->right;
			}

			//If the right child of the predecessor is null, then set the right child to the current node, and the current node
			//to the left child
			if (prev->right == NULL)
			{
				prev->right = current;
				current = current->left;
			}
			else
			{
				//Set the right child to null, print the value of the current node, and set the current node to it's right child
				prev->right = NULL;
				printf("%d ", current->getKey());
				current = current->right;
			}			
		}
	}
}

void BinaryTree::preorderTraversalrec(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	//If the node isn't null, then visit the root, followed by traversing left and right subtrees recursively.
	printf("%d ",node->getKey());

	preorderTraversalrec(node->left);
	preorderTraversalrec(node->right);
}

void BinaryTree::preorderTraversalit(Node* node)
{	
	stack<Node*>nodes;
	nodes.push(node);
	
	while (!nodes.empty())
	{
		//Grab the node at the top of the stack, print it, then pop the stock
		Node* node = nodes.top();
		printf("%d ", node->getKey());
		nodes.pop();

		//If the top node's right child isn't null, then push it onto the stack
		if (node->right)
		{
			nodes.push(node->right);
		}

		//If the top node's left child isn't null, then push it onto the stack
		if (node->left)
		{
			nodes.push(node->left);
		}
	}
}

void BinaryTree::postorderTraversalrec(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	//If the node isn't null then traverse left and right subtrees recursively, followed by visiting the root
	postorderTraversalrec(node->left);
	postorderTraversalrec(node->right);

	printf("%d ", node->getKey());
}

void BinaryTree::postorderTraversalit(Node* node)
{
	stack<Node*>nodes;
	nodes.push(node);

	while (!nodes.empty())
	{		
		while (node)
		{
			//If the node's right child isn't null, then push it onto the stack, followed by the currrent node
			if (node->right)
			{
				nodes.push(node->right);
			}
			nodes.push(node);
			//Set the current node to it's left child
			node = node->left;
		}
		//Set the current node to the top of the stack and pop the stack
		node = nodes.top();
		nodes.pop();

		if (!nodes.empty())
		{
			//If the node's right child isn't null, and the top of the stack is equal to the node's right child,
			//then pop the stack, push the current node, and assign the current node's right child as the current node
			if (node->right && nodes.top() == node->right)
			{
				nodes.pop();
				nodes.push(node);
				node = node->right;
			}
			else
			{
				//Print the value of the current node, and point it to null
				printf("%d ", node->getKey());
				node = NULL;
			}
		}
		
	}
}




