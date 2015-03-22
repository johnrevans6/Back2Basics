#include "binarytree.h"
#include <vector>
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
	if (node == NULL)
	{
		return;
	}

	inorderTraversalrec(node->left);
	printf("%d ", node->getKey());
	inorderTraversalrec(node->right);
	
}

void BinaryTree::preorderTraversalrec(Node* node)
{
	if (node == NULL)
	{
		return;
	}

	printf("%d ",node->getKey());

	preorderTraversalrec(node->left);
	preorderTraversalrec(node->right);
}

void BinaryTree::postorderTraversalrec(Node* node)
{
	if (node == NULL)
	{
		return;
	}

	postorderTraversalrec(node->left);
	postorderTraversalrec(node->right);

	printf("%d ", node->getKey());
}




