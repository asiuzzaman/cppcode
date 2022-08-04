#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// A recursive CPP program to find
// LCA of two nodes n1 and n2.
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left, * right;
};

/* Function to find LCA of n1 and n2.
The function assumes that both
n1 and n2 are present in BST */
node* lca(node* root, int n1, int n2)
{
	if (root == NULL) return NULL;

	// If both n1 and n2 are smaller
	// than root, then LCA lies in left
	if (root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);

	// If both n1 and n2 are greater than
	// root, then LCA lies in right
	if (root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);

	return root;
}

/* Helper function that allocates
a new node with the given data.*/
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return(Node);
}

int secondBS(vector<int>matrix, int x) {
	int i = matrix[0];
	int l = matrix.size();
	int j = matrix[l - 1];

	int mid;

	while (i <= j) {
		mid = (i + j) / 2;

		if (mid < x) {
			i = mid + 1;
		}
		else {
			j = mid - 1;
		}

	}
	return i;
}

int kthSmallest(vector< vector<int> > matrix, int k) {
	int i = matrix[0][0];
	int m = matrix.size();
	int n = matrix[0].size();

	int j = matrix[m-1][n-1];

	int mid;
	int ans = 0;
	while (i <= j) {
		mid = (i + j) / 2;
		int t = secondBS(matrix[i], mid);
		if (t < k) {
			ans = mid;
			i = mid + 1;
		}
		else {
			j = mid - 1;;
		}
	}
	return ans;
}
/* Driver code*/
int main()
{
	// Let us construct the BST
	// shown in the above figure
	node* root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	/*int n1 = 10, n2 = 14;
	node* t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

	n1 = 10, n2 = 22;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
	return 0;*/

	/*int matrix[100][100];

	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[1][0] = 1;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			matrix[i][j] = 1;
		}
	}

	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
		}
	}*/


	/*int matrix[3][3] = {
		{ 1, 5, 9 }, 
		{ 10,11,13 }, 
		{ 12,13,15 }
	};*/
	  
	vector< vector<int> > matrix = {
		{ 1, 5, 9 },
		{ 10,11,13 },
		{ 12,13,15 }
	};

	int t = matrix[0][2];

	int a = kthSmallest(matrix, 8);

	//2d binarySearch


}

