/*
 * linked_list.cc
 *
 *  Created on: Apr 3, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node
{
	int data;
	node* next;
};

void create_list(vector<int> array, node** list)
{
	node* head = new node();
	node* ptr = head;
	size_t i = 0;

	for (; i < array.size() - 1; ++i)
	{
		ptr->data = array[i];
		ptr->next = new node();
		ptr = ptr->next;
	}

	ptr->data = array[i];
	ptr->next = NULL;

	*list = head;
}

void print_list(node* list)
{
	cout << "[";
	while (list)
	{
		cout << list->data << ", ";
		list = list->next;
	}
	cout << "]" << endl;
}

void delete_value(node** list, int value)
{
	node* prev = NULL;
	node* ptr = *list;

	while (ptr)
	{
		if (ptr->data == value)
		{
			if (prev == NULL)
			{
				// head node
				node *del = ptr;
				ptr = ptr->next;
				*list = ptr; // reset head
				delete (del);
			}
			else
			{
				prev->next = ptr->next;
				delete (ptr);
				ptr = prev->next;
			}
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}

}

void delete_node(node* ptr)
{
	if (ptr->next == NULL)
	{
		cerr << "Invalid node: can't delete tail node!";
	}
	else
	{
		node* del = ptr->next;
		ptr->data = del->data;
		ptr->next = del->next;
		delete (del);
	}
}

void delete_list(node** list)
{
	node* ptr = *list;
	if(ptr->next == NULL)
	{
		delete ptr;
		ptr = NULL;
	}
	else
	{
		delete_list(&ptr->next);
		ptr->next = NULL;
		delete ptr;
		ptr = NULL;
		*list = ptr;
	}
}

void linked_list_run()
{
	int arr[] = { 1, 2, 1, 6, 5 };
	vector<int> v(arr, arr + 5);

	node* list;

	create_list(v, &list);
	print_list(list);

	delete_value(&list, 6);
	print_list(list);

	delete_node(list->next);
	print_list(list);

	delete_list(&list);
	print_list(list);
}
