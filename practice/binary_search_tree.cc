/*
 * binary_search_tree.cc
 *
 *  Created on: Apr 3, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
class binary_search_tree
{

private:

	node<T> *root;

protected:

	node<T>* buildTree(vector<T> sortedArray, int left, int right)
	{
		if (left > right)
		{
			return NULL;
		}

		size_t mid = (left + right) / 2;
		node<T>* n = new node<T> ();
		n->data = sortedArray[mid];
		n->left = buildTree(sortedArray, left, mid - 1);
		n->right = buildTree(sortedArray, mid + 1, right);
		return n;
	}

public:

	binary_search_tree(vector<T> sortedArray)
	{
		root = buildTree(sortedArray, 0, sortedArray.size() - 1);
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

	node<T>* getRoot()
	{
		return root;
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

	void simpleprint(node<T>* root)
	{
		if (root == NULL)
		{
			cout << "-";
			return;
		}

		cout << '(' << root->data;

		// for both null children we don't write '--'
		if (!(root->left == NULL && root->right == NULL))
		{
			simpleprint(root->left);
			simpleprint(root->right);
		}
		cout << ')';
	}

	node<T>* search(node<T>* n, T val)
	{
		if (n == NULL || n->data == val)
		{
			return n;
		}

		if (val < n->data)
		{
			return search(n->left, val);
		}
		else
		{
			return search(n->right, val);
		}
	}

	node<T>* insertNode(node<T>*n, T val)
	{
		if (val < n->data)
		{
			if (n->left != NULL)
			{
				return insertNode(n->left, val);
			}
			else
			{
				n->left = new node<T> ();
				n->left->data = val;
				return n->left;
			}
		}
		else
		{
			if (n->right != NULL)
			{
				return insertNode(n->right, val);
			}
			else
			{
				n->right = new node<T> ();
				n->right->data = val;
				return n->right;
			}

		}
	}

	void deleteNode(T val)
	{
		// TODO: Implement
	}

};

void binary_search_tree_run()
{
	int arr[] =
	{ 1, 2, 3, 4, 5, 6, 7 };
	//{ 9, 12, 14, 17, 19, 23, 50, 54, 67, 72, 76 };

	vector<int> v(arr, arr + 7);
	binary_search_tree<int> t(v);

	cout << "BST Root: " << t.getRoot()->data;

	cout << "\nInorder: ";
	t.inorder(t.getRoot());

	cout << "\nSimplePrint: ";
	t.simpleprint(t.getRoot());

	cout << "\nSearch(6): " << t.search(t.getRoot(), 6);
	cout << "\nSearch(8): " << t.search(t.getRoot(), 8);

	cout << "\nInsert(8): " << t.insertNode(t.getRoot(), 8);
	cout << "\nSearch(8): " << t.search(t.getRoot(), 8);

	cout << "\nSimplePrint: ";
	t.simpleprint(t.getRoot());
}
