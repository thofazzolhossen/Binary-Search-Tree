
#include <iostream>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;
Node(int val){
  data= val;
  left=NULL;
  right=NULL;
}
};
/* Alternative method
bool check ( node* p1 , node *p2 )
{
  if( p1 ==NULL && p2 ==NULL )
     return true;

  if( p1 !=NULL && p2 !=NULL )
    return  ( check ( p1 -> left , p2 -> left ) && check ( p1 -> right , p2 -> right ) );
 return false ;
}*/

bool isIdentical(Node* root1, Node* root2){

      if(root1==NULL && root2 ==NULL){
        return true;
      }
       if(root1 == NULL || root2== NULL){
        return false;
      }
     else {
        bool cond1= root1->data == root2->data;
        bool cond2= isIdentical(root1->left , root2->left);
        bool cond3= isIdentical(root1->right , root2->right);

        if(cond1 && cond2 && cond3) {
              return true;
          }
       return false;
      }
  }


int main() {
Node* root1=new Node(6);
  root1->left=new Node(4);
  root1->right=new Node(7);



Node* root2=new Node(6);
  root2->left=new Node(4);
  root2->right=new Node(8);


  if(isIdentical(root1, root2)){
    cout<<"BST are identical";
    }
  else{
  cout<<"Not Identical";
  }
  }
