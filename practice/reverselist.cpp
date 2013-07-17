#include <iostream>

using namespace std;

struct node
{
	node* next;
	int data;
    
    node()
    {
        next = NULL;
        data = 0;
    }
};

void createlist(node*& head)
{
	node *prev = NULL;

	for(int i=1; i<5; i++)
	{
		node *tmp = new node();
		tmp->data = i;
		if(!prev)
		{
			head = tmp;
		}
		else
		{
			prev->next = tmp;
		}
        prev = tmp;
	}
}
		
void printlist(node *head)
{
	if(!head)
		return;

	cout<<head->data<<" ";
	printlist(head->next);
}


void reverse(node*& head)
{
	node *prev = NULL;
	node *cur = head;
	
	while(cur)
	{
		node *tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
	}
    
    head = prev;
}

int main()
{
	node *p;
	createlist(p);
	printlist(p);
	cout<<endl;
	reverse(p);
	printlist(p);
	cout<<endl;
	return 0;
}