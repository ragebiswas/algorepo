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

void inorder_recursive(node *n)
{
	if(!n)
		return;
	inorder_recursive(n->left);	
	cout<<n->data<<" ";
	inorder_recursive(n->right);
}

void inorder_iterative(node* n)
{
	stack<node*> st;
	node *p = n;
	while(1)
	{
		if(!p)
			return;
		
		while(p)	
		{
			st.push(p);
			p = p->left;
		}
		
		while(!st.empty())
		{
			node *t = st.top();
			st.pop();
			cout<<t->data<<" ";
			
			if(t->right)
			{
				p = t->right;
				break;
			}
		}		
	}
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v(arr, arr+7);
	node *root = build_tree(v, 0, v.size()-1);
	cout<<"Inorder Recursive: "; 
	inorder_recursive(root);
	cout<<endl;
	
	cout<<"Inorder Iterative: "; 
	inorder_iterative(root);
	cout<<endl;


	return 0;
}