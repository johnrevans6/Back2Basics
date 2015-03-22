#ifndef BINARY_TREE
#define BINARY_TREE
#include <vector>
#include <iostream>
using namespace std;

class BinaryTree
{
public:
	class Node
	{
	public:
		Node(){};
		Node* left;
		Node* right;
		int getKey(){ return key; };
		void setKey(int k){ key = k; }
	private:
		int key;		
	};

	BinaryTree();
	~BinaryTree();
	

	Node* search(int k);

	Node* getRoot(){ return root; };

	void insert(int k);
	void inorderTraversalrec(Node* node);
	void preorderTraversalrec(Node* node);
	void postorderTraversalrec(Node* node);

	void destroyTree();
	
private:
	void insert(Node* leaf, int k);
	void destroyTree(Node* leaf);
	
	Node* search(Node* leaf, int k);
	Node* root;

};


#endif