#include <iostream>
#include <set>
using namespace std;

//Represent a node of binary tree
struct node{
    int data;
    struct node *left;
    struct node *right;
};

//Represent the root of binary tree
struct node *root = NULL;

int treeArray[100];
int ind = 0;

//createNode() will create a new node
struct node* createNode(int data){
    //Create a new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    //Assign data to newNode, set left and right children to NULL
    newNode->data= data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

//calculateSize() will calculate size of tree (BT to BST)
int calculateSize(struct node *node)
{
    int size = 0;
    if (node == NULL)
     return 0;
    else {
size = calculateSize (node->left) + calculateSize (node->right) + 1;
        return size;
    }
}

//convertBTtoArray() will convert the given binary tree to its corresponding array representation
void convertBTtoArray(struct node *node) {
    //Check whether tree is empty
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {
        if(node->left != NULL)
            convertBTtoArray(node->left);
        //Adds nodes of binary tree to treeArray
        treeArray[ind] = node->data;
        ind++;
        if(node->right!= NULL)
            convertBTtoArray(node->right);
        }
}

//createBST() will convert array to binary search tree
struct node* createBST(int start, int end) {

    //It will avoid overflow
    if (start > end) {
        return NULL;
    }

    //Variable will store middle element of array and make it root of binary search tree
    int mid = (start + end) / 2;
    struct node *temp = createNode(treeArray[mid]);

    //Construct left subtree
    temp->left = createBST(start, mid - 1);

    //Construct right subtree
    temp->right = createBST(mid + 1, end);

    return temp;
}

//convertBTBST() will convert a binary tree to binary search tree
struct node* convertBTBST(struct node *node) {

    //Variable treeSize will hold size of tree
    int treeSize = calculateSize(node);

    //Converts binary tree to array
    convertBTtoArray(node);

    //Sort treeArray
    int compare (const void * a, const void * b) {
        return ( *(int*)a - *(int*)b );
    }
    qsort(treeArray, treeSize, sizeof(int), compare);

    //Converts array to binary search tree
    struct node *d = createBST(0, treeSize - 1);
    return d;
}

//inorder() will perform inorder traversal on binary search tree
void inorderTraversal(struct node *node) {

    //Check whether tree is empty
    if(root == NULL){
        printf("Tree is empty\n");
        return;
       }
    else {

        if(node->left!= NULL)
            inorderTraversal(node->left);
        printf("%d ", node->data);
        if(node->right!= NULL)
            inorderTraversal(node->right);
    }
}

int main()
{
    //Add nodes to the binary tree
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    //Display given binary tree
    printf("Inorder representation of binary tree: \n");
    inorderTraversal(root);

    //Converts binary tree to corresponding binary search tree
    struct node *bst = convertBTBST(root);

    //Display corresponding binary search tree
    printf("\nInorder representation of resulting binary search tree: \n");
    inorderTraversal(bst);

    return 0;
}
