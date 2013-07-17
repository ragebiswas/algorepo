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

void preorder_recursive(node *n)
{
	if(!n)
		return;
	cout<<n->data<<" ";
	preorder_recursive(n->left);
	preorder_recursive(n->right);
}

void preorder_iterative1(node* n)
{
	stack<node*> st;
	st.push(n);
	
	while(!st.empty())
	{
		cout<<n->data<<" ";
		n = n->left;
		if(n)
			st.push(n);
				
		while(!n && !st.empty())
		{
			node* p = st.top();
			st.pop();
			n = p->right;
			if(n)
				st.push(n);
		}
	}
}

void preorder_iterative2(node* n)
{
	stack<node*> st;
	st.push(n);

	while(!st.empty())
	{
		node *n = st.top();
		st.pop();
		
		if(n->right) 
			st.push(n->right);
		if(n->left)
			st.push(n->left);
		cout<<n->data<<" ";
	}
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v(arr, arr+7);
	node *root = build_tree(v, 0, v.size()-1);
	cout<<"Preorder Recursive: "; 
	preorder_recursive(root);
	cout<<endl;
	
	cout<<"Preorder Iterative1: "; 
	preorder_iterative1(root);
	cout<<endl;
	
	cout<<"Preorder Iterative2: "; 
	preorder_iterative2(root);
	cout<<endl;


	return 0;
}