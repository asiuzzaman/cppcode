#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *Insert(Node *root, int value){
    if(root==NULL){
        
        root=new Node();
        root->data=value;
        root->left=root->right=NULL;
    }
    else if(value>root->data){
        root->right=Insert(root->right,value);
    } else {
        root->left=Insert(root->left,value);
    }
    return root;
}

int maxDepth(Node * root){
  //  cout<<root->data<<endl;
    if(root==NULL) return 0;
    else{
        int lDepth=maxDepth(root->left);
        int rDepth=maxDepth(root->right);
        
        if(lDepth>rDepth) return lDepth+1;
        else return rDepth+1;
    }   
}

int main(){
    Node *root=NULL;
    root=Insert(root,5);
    root=Insert(root,4);
    root=Insert(root,10);
    root=Insert(root,3);
    root=Insert(root,8);
    root=Insert(root,11);
    root=Insert(root,33);
    root=Insert(root,7);
    root=Insert(root,6);
    // cout<<root->right->left->data<<endl;
    // cout<<root->left->left->data<<endl;
    
    cout<<maxDepth(root)<<endl;
    /*
    the output is : 8  3
        5
       / \
      4   10
     /   /  \
   3   8     11
               \
                33

    Rules to form a Binary tree :
    1. Base Case:
          if the root is null then a node is created with insert its value and left and 
          right child become null again.
    2. If the incoming value is lesser or equal than it's root then it's going to the left
    3. Otherwise going to the right. 
    */
    
    

}