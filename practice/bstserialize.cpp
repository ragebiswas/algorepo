#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

string int_to_string(const int& i)
{
	ostringstream oss;
	oss<<i;
	return oss.str();
}

int string_to_int(const string& s)
{
	istringstream iss(s);
	int i;
	iss>>i;
	return i;
}

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

void preorder(node *n)
{
	if(!n)
		return;
	cout<<n->data<<" ";
	preorder(n->left);
	preorder(n->right);
}


void serialize_bst(node* n, string& s)
{
	if(!n)
		return;
		
	s += int_to_string(n->data) + " ";
	serialize_bst(n->left, s);
	serialize_bst(n->right, s);
}

void deserialize_bst(node*& root, int& data, int min, int max, istringstream& iss)
{
	if(data >= min && data <= max)
	{
		root = new node(data);
				
		string s;
		if(iss>>s)
		{
			int olddata = data;
			data = string_to_int(s);
			deserialize_bst(root->left, data, min, olddata, iss);
			deserialize_bst(root->right, data, olddata, max, iss); 
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v(arr, arr+7);
	node *root = build_tree(v, 0, v.size()-1);
	preorder(root);
	cout<<endl;
	
	string s = "";
	serialize_bst(root, s);
	cout<<"Serialized: "<<s<<endl;
		
	istringstream iss(s);
	int first; 
	iss>>first;
	node *newroot;
	deserialize_bst(newroot, first, INT_MIN, INT_MAX, iss);
	cout<<"Deserialized: ";
	preorder(newroot);
	cout<<endl;	
	
	return 0;
	
}