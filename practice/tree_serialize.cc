/*
 * tree_serialize.cc
 *
 *  Created on: Apr 5, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

template<class T>
struct node
{
	T data;
	node* left;
	node* right;

	node()
	{
		left = NULL;
		right = NULL;
	}
};

template<class T>
class binary_tree
{

private:

	node<T> *root;

public:

	binary_tree()
	{
		root = NULL;
	}

	void preorder(node<T>* node)
	{
		if (node == NULL)
		{
			return;
		}
		cout << node->data << ",";
		preorder(node->left);
		preorder(node->right);
	}

	void inorder(node<T>* node)
	{
		if (node == NULL)
		{
			return;
		}
		inorder(node->left);
		cout << node->data << ",";
		inorder(node->right);
	}

	void postorder(node<T>* node)
	{
		if (node == NULL)
		{
			return;
		}
		postorder(node->left);
		postorder(node->right);
		cout << node->data << ",";

	}

	void levelorder(node<T>* n)
	{
		// queue< node<T>* > q;

		// more elegant:
		queue<typeof(n)> q;

		q.push(n);

		while (!q.empty())
		{
			n = q.front();
			q.pop();
			cout << n->data << ",";

			if (n->left != NULL)
			{
				q.push(n->left);
			}
			if (n->right != NULL)
			{
				q.push(n->right);
			}
		}
	}

	node<T>* getRoot()
	{
		return root;
	}

	void setRoot(node<T>* n)
	{
		root = n;
	}

	size_t height(node<T>* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		else
		{
			return 1 + max(height(node->left), height(node->right));
		}
	}

	void serialize(node<T>* n, string& str)
	{
		addnodetostring(n, str);
		str = "(" + str + ")";
	}

	void addnodetostring(node<T>* n, string& str)
	{
		string data;
		stringstream ss;

		if (n == NULL)
		{
			data = "-";
		}
		else
		{
			ss << n->data;
			data = ss.str();
		}

		str += data;

		if (n != NULL && !(n->left == NULL && n->right == NULL))
		{
			str += "(";
			addnodetostring(n->left, str);
			str += " ";
			addnodetostring(n->right, str);
			str += ")";
		}
	}

	void deserialize(string& str)
	{
		int index = 0;
		root = getnodefromstring(NULL, str, index);
	}

	node<T>* getnodefromstring(node<T>* parent, string& str, int& index)
	{
		if (parent = NULL)
		{
			parent = new node<T> ();
		}

		if (str[index] != '(')
		{
		}

		index++; // skip '('
		string val = getnextval(str, index);

	}

	string getnextval(string str, int index)
	{
		string ret = "";

		while (!isspace(str[index]))
		{
			ret += str[index];
			index++;
		}
	}

};

void tree_serialize_run()
{
	binary_tree<int> t;

	//string s = "(1(23))";
	//t.deserialize(s);

	node<int>* r = new node<int> ();
	r->data = 1;
	r->left = new node<int> ();
	r->left->data = 2;
	r->right = new node<int> ();
	r->right->data = 4;
	r->left->right = new node<int> ();
	r->left->right->data = 3;
	t.setRoot(r);

	cout << "\nPreorder: ";
	t.preorder(t.getRoot());

	cout << "\nInorder: ";
	t.inorder(t.getRoot());

	cout << "\nPostorder: ";
	t.postorder(t.getRoot());

	cout << "\nLevelOrder: ";
	t.levelorder(t.getRoot());

	string ser;
	t.serialize(t.getRoot(), ser);
	cout << "\nSerialized: " << ser;

	//t.deserialize(ser);
	//cout << "\nDeserialized LevelOrder: ";
	//t.levelorder(t.getRoot());

}
