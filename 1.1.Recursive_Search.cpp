/* C++ function to search a given key in a given BST.

Time complexity: O(h), where h is the height of the BST.
Auxiliary Space: O(h), where h is the height of the BST.
This is because the maximum amount of space needed
to store the recursion stack would be h. */
#include <iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* newNode(int data){
    node* temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

node * search(node * root, int key){
    if(root==NULL || root->data == key)
        return root;

    // if key is greater than root
    else if( root->data < key){
         search(root->right, key);
    }

    else if(root->data > key) search(root->left, key);
    else return NULL;

}

int main(){
    node * root = newNode(4);
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

    node* address = search(root, 4);
    cout<<address->data<<endl;
}
