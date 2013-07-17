#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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

void preorder(node *n)
{
	if(!n)
		return;
	cout<<n->data<<" ";
	preorder(n->left);
	preorder(n->right);
}


void serialize(node* n, string& s)
{
	if(!n)
	{
		s += "# ";
		return;
	}
	s += int_to_string(n->data) + " ";
	serialize(n->left, s);
	serialize(n->right, s);
}

node* deserialize(istringstream& iss)
{
	string tok;
	iss>>tok;
	
	if(tok == "#")
		return NULL;
		
	node* root = new node(string_to_int(tok));
	root->left = deserialize(iss);
	root->right = deserialize(iss);	
	return root;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v(arr, arr+7);
	node *root = build_tree(v, 0, v.size()-1);
	preorder(root);
	cout<<endl;
	
	string s = "";
	serialize(root, s);
	cout<<"Serialized: "<<s<<endl;
	
	istringstream iss(s);
	node *newroot = deserialize(iss);
	cout<<"Deserialized Preorder: ";
	preorder(newroot);
	cout<<endl;
	
	return 0;
}