/*
 * add_lists
 *
 *  Created on: Apr 4, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include<vector>

using namespace std;

using namespace std;

struct node
{
	int data;
	node* next;
};

// see removeduplist.cc or linked_list.cc
extern void create_list(vector<int> array, node** list);
extern void print_list(node* list);

void addlists(node* list1, node* list2, node** newlist)
{
	int carry = 0;
	int val1;
	int val2;

	node *cur = NULL;
	*newlist = NULL;

	while (list1 != NULL || list2 != NULL || carry)
	{
		if (!list1)
			val1 = 0;
		else
			val1 = list1->data;

		if (!list2)
			val2 = 0;
		else
			val2 = list2->data;

		int sum = val1 + val2 + carry;
		if (sum >= 10)
		{
			sum -= 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}

		node* n = new node();
		n->data = sum;

		if (*newlist == NULL)
		{
			*newlist = n;
			cur = n;
		}
		else
		{
			cur->next = n;
			cur = cur->next;
		}

		if (list1 != NULL)
			list1 = list1->next;

		if (list2 != NULL)
			list2 = list2->next;
	}

}

void addlists_run()
{
	int arr1[] =
	{ 3, 1, 5 };
	vector<int> v1(arr1, arr1 + 3);

	node* list1;
	create_list(v1, &list1);

	int arr2[] =
	{ 3, 1, 5 };
	vector<int> v2(arr2, arr2 + 3);

	node* list2;
	create_list(v2, &list2);

	node* sum;
	addlists(list1, list2, &sum);
	print_list(sum);

}
