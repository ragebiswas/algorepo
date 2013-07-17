#include <iostream>
#include <string>
#include <vector>
#include <queue>

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

// build from complete inorder
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

void levelorder(node *n)
{
	queue<node*> thislevel, nextlevel;
	thislevel.push(n);
	
	while(!thislevel.empty())
	{
		node* t = thislevel.front();
		thislevel.pop();
		cout<<t->data<<" ";
		if(t->left)
			nextlevel.push(t->left);
		if(t->right)
			nextlevel.push(t->right);
			
		if(thislevel.empty())
		{	
			cout<<endl;
			swap(thislevel, nextlevel);
		}
	}
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v(arr, arr+7);
	node *root = build_tree(v, 0, v.size()-1);
	cout<<"Level order: \n"; 
	levelorder(root);
	cout<<endl;
	
	return 0;
}