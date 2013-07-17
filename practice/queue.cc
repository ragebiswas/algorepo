/*
 * queue.cc
 *
 *  Created on: Apr 3, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>

using namespace std;

template<class T>
class queue
{

private:

	T *_queue;
	static size_t _capacity;

	size_t _head; // location of front of the queue
	size_t _tail; // location of where the *next* item will be inserted

public:

	queue()
	{
		// stores 'n-1' for n length array
		_queue = new T[_capacity];

		// initialized (empty)
		_head = _tail = 0;
	}

	void enqueue(T val)
	{
		if (isFull())
		{
			// resize
			size_t _newcapacity = 2 * _capacity;
			T* _newqueue = new T[_newcapacity];
			size_t index = 0;
			while (!isEmpty())
			{
				_newqueue[index++] = dequeue();
			}
			delete[] _queue;
			_queue = _newqueue;
			_capacity = _newcapacity;
			_head = 0;
			_tail = index;
		}

		_queue[_tail++] = val;

		if (_tail == _capacity)
		{
			_tail = 0;
		}
	}

	T dequeue()
	{
		T val = _queue[_head++];
		if (_head == _capacity)
		{
			_head = 0;
		}
		return val;
	}

	bool isFull()
	{
		// a space is reserved between the head and the tail always
		return (_head == ((_tail + 1) % _capacity));
	}

	bool isEmpty()
	{
		// when head == tail, queue is empty
		return (_head == _tail);
	}

	void print()
	{
		size_t index = _head;
		cout << "[";
		while (index != _tail)
		{
			cout << _queue[index];
			if (index == _capacity)
			{
				index = 0;
			}
			else
			{
				index++;
			}
		}
		cout << "]" << endl;
	}

};

template<class T> size_t queue<T>::_capacity = 3; // can store '3'

void queue_run()
{
	queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

	while (!q.isEmpty())
	{
		cout << q.dequeue() << ", ";
	}

}
