#ifndef HEADER_H
#define HEADER_H
/*
	Jason Trost
	February 22, 2013
	Question 2

Implement insert and delete in a tri-nary tree. Much like a binary-tree but with 3 child nodes for each parent	
instead of two -- with the left node being values < parent, the right node values > parent, and the middle node 
values == parent.

In this program I created a BST class template with insert, remove and print functions. 
In the main program I created a selection screen so when the program is run
you can enact insertion, removal, and printing as many times as you like
then you can exit by entering 0. The insertion and removal asks for an 
input to either insert or remove from the tree.

*****NOTE*****
This program prints out the tree in in-order traversal.

*/
#include <cstdlib>
#include <iostream>
#include <cstddef>
using namespace std;

template < typename T >
class BST{
private:
	typedef struct Node{
		T data;
		Node *right;
		Node *left;
		Node *middle;

		Node (const T & d = T( ), Node *p = NULL, Node *n = NULL, Node *m = NULL )
			: data (d), left (p), right (n), middle (m) { }
	} Node;

	Node *root;
	int count;

public:
	BST () : root (NULL), count (0) { }

	bool isEmpty (){ // checks if tree is empty
		return (count==0);
	}

	Node * findMin (Node *t) const{ // used for node removal
		if (t== NULL)
			return NULL;
		if (t->left == NULL)
			return t;
		return findMin (t->left);
	}

	void insert (const T & x, Node * & t){ // inserts a node into tree
		if (t == NULL)
			t = new Node (x, NULL, NULL, NULL);
		else if (x < t->data)
			insert (x, t->left);
		else if (x == t->data){
			Node *newNode = new Node (x, NULL, t->middle, NULL);
			t->middle = newNode;
		}
		else if (x > t->data)
			insert (x, t->right);
		count++;
	}

	void remove (const T & x, Node * & t){ // removes a node from tree
		if (t == NULL)
			return;
		if (x < t->data)
			remove (x, t->left);
		else if (t->data < x)
			remove (x, t->right);
		else if (t->data == x && t->middle != NULL)
			remove (x, t->middle);
		else if (t->left != NULL && t->right != NULL)
		{
			t->data = findMin (t->right)->data;
			remove (t->data, t->right);
		}
		else
		{
			Node *old = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete old;
			count--;
		}
	}

	void print (Node * & t){ // prints out tree in in-order traversal
		if (!isEmpty()){
			if (t->left != NULL)
				print (t->left);
			if (t->middle!=NULL)
				print (t->middle);
			cout << t->data;
			if (t->right != NULL)
				print (t->right);	
		}
		else
			cout << "Tree is Empty.";
	}
	Node * & getRoot (void){ // returns root node
		return *&root;
	}
};
#endif