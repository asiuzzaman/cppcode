/*
  Problem: Find all node a the level of k 
  k is counted from the root where the value of k is 0.
*/

#include <iostream>
using namespace std;
#define ll long long int

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void Inorder(Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

Node *Append(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
    {
        root->left = Append(root->left, data);
    }
    else
        root->right = Append(root->right, data);

    return root;
}

void PrintDist(Node * root,int k){
    if(root==NULL) return;
    if(k==0) {
        cout<<root->data<<" ";
        return;
    }
    else{
        PrintDist(root->left,k-1);
        PrintDist(root->right,k-1);
    }

}
int main()
{
    Node *root = NULL;
    int data;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        root = Append(root, data);
    }
    int k;cin>>k;
    PrintDist(root,k);
}

/*
7
4 2 8 1 5 99 0

Binary Search Tree
            4
           / \
          2   8
         /   / \
        1   5   99
       /
      0
*/