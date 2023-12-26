// CPP program to check if two BSTs contains
// same set of elements
/*Time Complexity: O( n ).
Auxiliary Space: O( n ).*/
#include<bits/stdc++.h>
using namespace std;

// BST Node
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

// Utility function to create new Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

// function to insert elements of the
// tree to map m
void storeInorder(Node* root, vector<int> &v)
{
	if (!root)
		return;
	storeInorder(root->left, v);
	v.push_back(root->data);
	storeInorder(root->right, v);
}

// function to check if the two BSTs contain
// same set of elements
bool checkBSTs(Node* root1, Node* root2)
{
	// Base cases
	if (!root1 && !root2)
		return true;
	if ((root1 && !root2) || (!root1 && root2))
		return false;

	// Create two vectors and store
	// inorder traversals of both BSTs
	// in them.
	vector<int> v1, v2;
	storeInorder(root1, v1);
	storeInorder(root2, v2);

	// Return true if both vectors are
	// identical
	return (v1 == v2);
}

// Driver program to check above functions
int main()
{
	// First BST
	Node* root1 = newNode(15);
	root1->left = newNode(10);
	root1->right = newNode(20);
	root1->left->left = newNode(5);
	root1->left->right = newNode(12);
	root1->right->right = newNode(25);

	// Second BST
	Node* root2 = newNode(15);
	root2->left = newNode(12);
	root2->right = newNode(20);
	root2->left->left = newNode(5);
	root2->left->left->right = newNode(10);
	root2->right->right = newNode(25);

	// check if two BSTs have same set of elements
	if (checkBSTs(root1, root2))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
