#include <iostream>
#include <vector>

using namespace std;

struct node
{
	node* next;
	int data;
	
	node()
	{
		this->data = 0;
		this->next = NULL;
	}
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void create(node*& head, const vector<int>& v)
{
	if(v.empty())
		return;
	
	head = new node(v[0]);
	node *prev = head;
		
	for(size_t i=1; i<v.size(); i++)
	{
		node *n = new node(v[i]);
		prev->next = n;
		prev = n;
	}
}		
	
void print(node* head)
{
	if(!head) 
		return;
		
	cout<<head->data<<" ";
	print(head->next);
}		


void merge(node* list1, node* list2, node*& merged)
{
	merged = new node;
	node* head = merged;
	
	while(list1 && list2)
	{
		if(list1->data < list2->data)
		{
			merged->data = list1->data;
			list1 = list1->next;
			if(list1)
			{	
				merged->next = new node;
				merged = merged->next;
			}
		}
		else
		{
			merged->data = list2->data;
			list2 = list2->next;
			if(list2)
			{
				merged->next = new node;
				merged = merged->next;
			}
		}
	}	
	
	if(list1)
	{
		merged->next = new node;
		merged = merged->next;
	}
	
	while(list1)
	{
		merged->data = list1->data;
		list1 = list1->next;
		if(list1)
		{
			merged->next = new node;
			merged = merged->next;
		}
	}

	if(list2)
	{
		merged->next = new node;
		merged = merged->next;
	}
	
	while(list2)
	{
		merged->data = list2->data;
		list2 = list2->next;
		if(list2)
		{	
			merged->next = new node;
			merged = merged->next;
		}
	}

	merged = head;
}

int main()
{
	int a1[] = { 2, 4, 6, 8, 10, 12 };
	int a2[] = { 3, 5, 7, 11 };
	vector<int> v1(a1, a1 + 6);
	vector<int> v2(a2, a2 + 4);	
	
	node *list1;
	node *list2;
	create(list1, v1);
	create(list2, v2);
	node *merged;
	merge(list1, list2, merged);
	print(merged);
	
	return 0;
}