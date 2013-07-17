/*
 * removedupchars.cc
 * 		careercup problem 1.3
 *  Created on: Mar 31, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>

using namespace std;

string removedups(string str)
{
	int len = str.size();
	int last = 0;
	bool found;

	for (int i = 0; i < len; ++i)
	{
		found = false;
		for (int j = i + 1; j < len; ++j)
		{
			if (str[j] == str[i])
			{
				found = true;
			}
		}

		if (!found)
		{
			str[last] = str[i];
			last++;
		}
	}

	str.erase(str.begin() + last, str.end());

	return str;
}

void removedups_run()
{
	cout << removedups("abcd") << endl;
	cout << removedups("abcda") << endl;
	cout << removedups("abab") << endl;
	cout << removedups("aaaaaaaabbbbbbbbbbbbbcaaaaaaaaa") << endl;
}
