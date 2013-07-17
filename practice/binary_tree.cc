/*
 * binary_tree.cc
 *
 *  Created on: Apr 3, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

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

	binary_tree(vector<T> array)
	{
		root = NULL;
		node<T>* nodes = new node<T> [array.size()];

		for (size_t i = 0; i < array.size(); ++i)
		{
			nodes[i].data = array[i];
		}

		for (size_t i = 0; i < array.size() / 2; ++i)
		{
			node<T>* n = &nodes[i];
			n->left = &nodes[2 * i + 1];
			n->right = &nodes[2 * i + 2];
		}

		root = &nodes[0];
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

	void preorder_iterative(node<T>* root)
	{
		stack<node<T>* > pstack;
		pstack.push(root);

		while(!pstack.empty())
		{
			node<T>* n = pstack.top();
			pstack.pop();

			cout << n->data << ",";

			if(n->right)
				pstack.push(n->right);
			if(n->left)
				pstack.push(n->left);
		}
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

	void inorder_iterative(node<T>* root)
	{
		stack<node<T>* > pstack;
		node<T>* n = root;

		while(1)
		{
			if(n)
			{
				pstack.push(n);
				n = n->left;
				continue;
			}

			if(pstack.empty())
				return;

			n = pstack.top();
			pstack.pop();

			cout << n->data << ",";
			n = n->right;
		}
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
		queue< node<T>* > q;
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

	void prettyPrint()
	{

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

	void toArray(node<T>* n, vector<T>& v, size_t index)
	{
		if(n == NULL)
		{
			return;
		}

		v[index] = n->data;
		toArray(n->left, v, 2*index+1);
		toArray(n->right, v, 2*index+2);
	}

};

void binary_tree_run()
{
	int arr[] =
	{ 4, 2, 6, 1, 3, 5, 7 };
	vector<int> v(arr, arr + 7);
	binary_tree<int> t(v);

	cout << "\nPreorder Recursive: ";
	t.preorder(t.getRoot());

	cout << "\nPreorder Iterative: ";
	t.preorder_iterative(t.getRoot());

	cout << "\nInorder Recursive: ";
	t.inorder(t.getRoot());

	cout << "\nInorder Iterative: ";
	t.inorder_iterative(t.getRoot());

	cout << "\nPostorder Recursive: ";
	t.postorder(t.getRoot());

	cout << "\nLevelOrder: ";
	t.levelorder(t.getRoot());

	cout << "\nHeight: " << t.height(t.getRoot());

	vector<int> v2((1 << t.height(t.getRoot())) - 1);
	t.toArray(t.getRoot(), v2, 0);
	cout<<"\nToArray: ";
	for(size_t i = 0; i < v2.size(); ++i)
	{
		cout<<v2[i]<<",";
	}

}
