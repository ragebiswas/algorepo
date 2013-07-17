/*
 * stack.cc
 *
 *  Created on: Apr 3, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template<class T>
class stack
{

private:

	T *_stack;
	size_t _size;
	static size_t _capacity;


public:

	stack()
	{
		_stack = new T[_capacity];
		_size = 0;
	}

	void push(T val)
	{
		if (_size == _capacity)
		{
			// resize
			size_t _newcapacity = 2 * _capacity;
			T* _newstack = new T[_newcapacity];
			copy(_stack, _stack + _size, _newstack);
			delete[] _stack;
			_stack = _newstack;
			_capacity = _newcapacity;
		}
		_stack[_size++] = val;
	}

	T pop()
	{
		return _stack[--_size];
	}

	bool isEmpty()
	{
		return (_size == 0);
	}
};

template<class T> size_t stack<T>::_capacity = 3;

void stack_run()
{
	stack<int> int_stack;
	stack<string> string_stack;

	// test int stack
	int_stack.push(4);
	int_stack.push(7);
	int_stack.push(2);
	int_stack.push(3);

	while (!int_stack.isEmpty())
	{
		cout << "Popped: " << int_stack.pop() << " ";
	}
	cout << endl;

	// test string stack
	string_stack.push("hello");
	string_stack.push("world");
	string_stack.push("rajorshi");
	string_stack.push("biswas");

	while (!string_stack.isEmpty())
	{
		cout << "Popped: '" << string_stack.pop() << "' ";
	}
	cout << endl;

}
