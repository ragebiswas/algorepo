/*
 * stackwithqueues.cc
 *
 *  Created on: Apr 4, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

template<class T>
class stackwithqueues
{

private:

	queue<T> q1;
	queue<T> q2;

public:
	void push(T val)
	{
		q1.push(val);
	}

	T pop()
	{
		while (q1.size() > 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		T front = q1.front();
		q1.pop();

		queue<T> temp = q1;
		q1 = q2;
		q2 = temp;

		return front;
	}

	bool isEmpty()
	{
		return (q1.empty() && q2.empty());
	}
};

void stackwithqueues_run()
{
	stackwithqueues<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout << q.pop() << endl;
	q.push(40);
	q.push(50);
	while (!q.isEmpty())
		cout << q.pop() << endl;
}
