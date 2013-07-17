/*
 * removeduplist.cc
 *
 *  Created on: Apr 4, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include<vector>

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

void removedups(node** head)
{
	node* cur = (*head)->next;

	node* scanner = *head;
	node* scannerprev = NULL;

	while (cur != NULL)
	{
		scanner = *head;
		scannerprev = NULL;

		while (scanner != cur)
		{
			if (scanner->data == cur->data)
			{
				if (scannerprev == NULL)
				{
					*head = scanner->next;
					delete scanner;
				}
				else
				{
					node *temp = scannerprev->next;
					scannerprev->next = scannerprev->next->next;
					delete temp;
				}
				break;
			}
			else
			{
				scannerprev = scanner;
				scanner = scanner->next;
			}
		}

		cur = cur->next;
	}
}

void removeduplist_run()
{
	int arr[] =
	{  6, 7, 1, 1, 6 };
	vector<int> v(arr, arr + 5);

	node* list;

	create_list(v, &list);
	print_list(list);

	removedups(&list);
	print_list(list);

}
