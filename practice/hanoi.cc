/*
 * hanoi.cc
 *
 *  Created on: Apr 4, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<class T>
class namedstack: public stack<T>
{
private:
	string _name;
public:
	namedstack(string name)
	{
		::stack<T>();
		_name = name;
	}

	string name()
	{
		return _name;
	}
};

void hanoi(size_t size, namedstack<char>& src, namedstack<char>& dest,
		namedstack<char>& via)
{
	if (size == 1)
	{
		char srctop = src.top();
		src.pop();
		dest.push(srctop);
		cout << "Moved " << srctop << " from " << src.name() << " to "
				<< dest.name() << endl;
		return;
	}
	else
	{
		hanoi(size - 1, src, via, dest);
		char srctop = src.top();
		src.pop();
		dest.push(srctop);
		cout << "Moved " << srctop << " from " << src.name() << " to "
				<< dest.name() << endl;
		hanoi(size - 1, via, dest, src);
	}
}

void hanoi_run()
{
	namedstack<char> a("stack1");
	namedstack<char> b("stack2");
	namedstack<char> c("stack3");

	a.push('C');
	a.push('B');
	a.push('A');

	hanoi(a.size(), a, c, b);
}
