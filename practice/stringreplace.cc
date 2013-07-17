/*
 * stringreplace.cc
 * 		careercup problem 1.5
 *
 *  Created on: Mar 31, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string replace(string str)
{
	int spacecount = count(str.begin(), str.end(), ' ');
	int len = str.size();

	int rindex = str.size() - 1;

	str.resize(len + 2 * spacecount);

	int windex = str.size() - 1;

	while (rindex >= 0)
	{
		if (str[rindex] == ' ')
		{
			str[windex--] = '0';
			str[windex--] = '2';
			str[windex--] = '%';
		}
		else
		{
			str[windex--] = str[rindex];
		}

		rindex--;
	}

	return str;
}

void replace_run()
{
	cout << replace("Hello world") << endl;
	cout << replace("This is a long line") << endl;
	cout << replace("Nospaces") << endl;
}
