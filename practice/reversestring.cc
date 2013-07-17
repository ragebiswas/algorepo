/*
 * reversestring.cc
 * 		careercup problem 1.2
 *
 *  Created on: Mar 31, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>

using namespace std;

string reversestring(string s)
{
	int len = s.size();
	for (int i = 0; i < len / 2; ++i)
	{
		char t = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = t;
	}
	return s;
}

void reversestring_run()
{
	cout << reversestring("abcde") << endl;
	cout << reversestring("hello world!") << endl;
}
