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

void postorder_recursive(node *n)
{
	if(!n)
		return;
	postorder_recursive(n->left);	
	postorder_recursive(n->right);
	cout<<n->data<<" ";
}

void postorder_iterative(node* n)
{
	stack<node*> s1, s2;
	s1.push(n);
	
	while(!s1.empty())
	{
		node *t = s1.top();
		s1.pop();
		
		s2.push(t);
		
		if(t->left)
			s1.push(t->left);
		if(t->right)
			s1.push(t->right);			
	}	
	
	while(!s2.empty())
	{
		node *t = s2.top();
		s2.pop();
		cout<<t->data<<" ";
	}
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v(arr, arr+7);
	node *root = build_tree(v, 0, v.size()-1);
	cout<<"Postorder Recursive: "; 
	postorder_recursive(root);
	cout<<endl;
	
	cout<<"Postorder Iterative: "; 
	postorder_iterative(root);
	cout<<endl;


	return 0;
}