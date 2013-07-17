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

void removedups(node* list)
{
	if(!list || !list->next)
		return;
	
	node *wpos, *rpos;
	wpos = list->next;
	rpos = list->next->next;
	
	while(rpos)
	{
		node *p = list;
		int val = rpos->data;
		
		while(p != rpos)
		{
			if(p->data == val)
				break;
			p = p->next;
		}
		
		if(p == rpos)
		{
			wpos->next->data = val;
			wpos = wpos->next;
		}
		rpos = rpos->next;
	}
	wpos->next = NULL;
}


int main()
{
	int a[] = { 2, 14, 1, 5, 2, 6, 1, 4, 2, 2 };
	vector<int> v(a, a + 10);

	node *list;
	create(list, v);
	cout<<"List : "; print(list); cout<<endl;
	removedups(list);	
	cout<<"List : "; print(list); cout<<endl;

	return 0;
}