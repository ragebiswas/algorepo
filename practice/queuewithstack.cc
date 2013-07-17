/*
 * queuewithstack.cc
 *
 *  Created on: Apr 4, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<class T>
class queuewithstacks
{
private:

	stack<T> insertStack;
	stack<T> removeStack;

public:
	void enqueue(T val)
	{
		insertStack.push(val);
	}

	T dequeue()
	{
		if (removeStack.empty())
		{
			while (!insertStack.empty())
			{
				T temp = insertStack.top();
				insertStack.pop();
				removeStack.push(temp);
			}
		}

		T temp = removeStack.top();
		removeStack.pop();
		return temp;
	}

	T peek()
	{
		if (removeStack.empty())
		{
			while (!insertStack.empty())
			{
				T temp = insertStack.top();
				insertStack.pop();
				removeStack.push(temp);
			}
		}

		T temp = removeStack.top();
		return temp;
	}

	bool isEmpty()
	{
		return (insertStack.empty() && removeStack.empty());
	}

};

void queuewithstack_run()
{
	queuewithstacks<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	cout << q.dequeue() << endl;
	q.enqueue(40);
	q.enqueue(50);
	while (!q.isEmpty())
		cout << q.dequeue() << endl;
}
