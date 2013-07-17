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

void split(node* list, node*& first, node*& second)
{
	first = list;	
	node* slow = list;
	node* fast = list;
	
	while(slow && fast)
	{
		if(!fast->next || !fast->next->next)
		{
			second = slow->next;
			slow->next = NULL;
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}	
}


int main()
{
	int a[] = { 12, 14, 16, 18, 10, 22, 24, 26, 30, 32 };
	vector<int> v(a, a + 10);

	node *list;
	node *list1, *list2;
	create(list, v);

	split(list, list1, list2);
	cout<<"List 1: "; print(list1); cout<<endl;
	cout<<"List 2: "; print(list2); cout<<endl;

	return 0;
}