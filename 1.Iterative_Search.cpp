/*
Time Complexity: O(h), here h is the height of the BST.
Auxiliary Space: O(1), as constant extra space is used.
*/
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


bool iterativeSearch(struct Node* root, int key)
{
    // Traverse until root reaches to dead end
    while (root != NULL) {
        // pass right subtree as new tree
        if (key > root->data)
            root = root->right;

        // pass left subtree as new tree
        else if (key < root->data)
            root = root->left;
        else
            return true; // if the key is found return 1
    }
    return false;
}



int main(){
    Node * root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    /*
                   4
                 /   \
                2     5
               / \
              1   3

        */

    if (iterativeSearch(root, 5))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
