#include <iostream>
#include <stack>
using namespace std;

template<class T>
class QueueWithStack
{
private:
	stack<T> _enqstack, _deqstack;
	
public:
	bool empty()
	{
		return _enqstack.empty() && _deqstack.empty();
	}
	
	void enqueue(const T& val)
	{
		_enqstack.push(val);
	}
	
	T dequeue()
	{
		while(!_enqstack.empty())
		{
			T val = _enqstack.top();
			_enqstack.pop();
			_deqstack.push(val);
		}
		
		T ret = _deqstack.top();
		_deqstack.pop();
		return ret;
	}
	
};


int main()
{
	QueueWithStack<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	
	while(!q.empty())
	{
		cout<<"Dequeue first set: "<<q.dequeue()<<endl;
	}

	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);		
	
	while(!q.empty())
	{
		cout<<"Dequeue second set: "<<q.dequeue()<<endl;
	}
	
	return 0;
}