/*
 * stacksort.cc
 *
 *  Created on: Apr 4, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <stack>

#include <cstdlib>
#include <ctime>

using namespace std;

void stacksort(stack<int>& s)
{
	stack<int> auxstack;

	while (!s.empty())
	{
		int val = s.top();
		s.pop();

		if (auxstack.empty() || val <= auxstack.top())
		{
			auxstack.push(val);
		}
		else
		{
			int numshift = 0;
			while (!auxstack.empty() && val > auxstack.top())
			{
				numshift++;
				s.push(auxstack.top());
				auxstack.pop();
			}

			auxstack.push(val);
			while (numshift--)
			{
				auxstack.push(s.top());
				s.pop();
			}
		}
	}

	s = auxstack;
}

void stacksort_run()
{
	stack<int> s;
	srand(time(NULL));

	for (size_t i = 0; i < 5; ++i)
	{
		int val = rand() % 100 + 1;
		cout << "Push: " << val << endl;
		s.push(val);
	}

	cout << flush;
	stacksort(s);

	while (!s.empty())
	{

		cout << "Pop: " << s.top() << endl;
		s.pop();
	}
}
