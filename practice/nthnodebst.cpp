#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


struct node
{
	int data;
	node *left;
	node *right;
	
	node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

// build from complete level order
node* build_tree(vector<int>& v, int left, int right)
{
	if(left > right)
		return NULL;
		
	int mid = (left + right)/2;
	node* root = new node(v[mid]);
	root->left = build_tree(v, left, mid - 1);
	root->right = build_tree(v, mid + 1, right);
	return root;
}

void inorder_recursive(node *n, int& k)
{
	if(!n)
		return;
	inorder_recursive(n->left, k);	
	k--;
	if(k==0)
		cout<<n->data<<" ";	
	inorder_recursive(n->right, k);
}



int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v(arr, arr+7);
	node *root = build_tree(v, 0, v.size()-1);
	
	int k = 3;
	cout<<"3rd node: "; 
	inorder_recursive(root, k);
	cout<<endl;

	return 0;
}