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


void sort(node* head)
{
	node *p1 = head;
	node *p2 = head->next;
	
	if(!p1 || !p2)
		return;
		
	bool swapped = true;
	
	while(p1 && swapped)
	{
		swapped = false;
		node *t =  head;
		while(t)
		{
			if(t->next && t->next->data < t->data)
			{
				swapped = true;
				swap(t->data, t->next->data);
			}
			
			t = t->next;
		}
		p1 = p1->next;
	}	
}

int main()
{
	int a[] = { 12, 4, 61, 18, 10, 12, 5, -20, 40, 9 };
	vector<int> v(a, a + 10);	
	
	node *list;
	create(list, v);
	cout<<"Original:"; print(list); cout<<endl;	
	sort(list);
	cout<<"Sorted  :"; print(list); cout<<endl;
	
	return 0;
}