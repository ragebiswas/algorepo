#include <iostream>
#include <stack>
using namespace std;

class QueueWithInt
{
private:
	int _var;
	
public:
	QueueWithInt()
	{
		_var = 1;
	}
	
	bool empty()
	{
		return (_var == 1);
	}
	
	void enqueue(const int val)
	{
		_var = _var * 10 + val;
	}
	
	int dequeue()
	{	
		int tmp = _var;
		int h = 1;
		while(tmp > 99)
		{
			tmp /= 10;	
			h *= 10;
		}		
		_var = _var % h + h;
		return tmp - 10;
	}
	
};


int main()
{
	QueueWithInt q;
	q.enqueue(0);
	q.enqueue(2);
	q.enqueue(9);
	q.enqueue(4);
	
	while(!q.empty())
	{
		cout<<"Dequeue first set: "<<q.dequeue()<<endl;
	}

	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(0);		
	
	while(!q.empty())
	{
		cout<<"Dequeue second set: "<<q.dequeue()<<endl;
	}
	
	return 0;
}