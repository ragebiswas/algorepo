/*
 * anagrams.cc
 * 		careercup problem 1.4
 *
 *  Created on: Mar 31, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool anagrams(string s1, string s2)
{

	// simplest way
	// sort(s1.begin(), s1.end());
	// sort(s2.begin(), s2.end());
	// return s1==s2;

	map<char, int> freq;
	int num_unique = 0;
	int num_checked = 0;

	for(unsigned i = 0; i < s1.size(); ++i)
	{
		if(freq.count(s1[i]) == 0)
		{
			num_unique++;
			freq[s1[i]] = 1;
		}
		else
		{
			freq[s1[i]]++;
		}
	}

	for(unsigned i = 0; i < s2.size(); ++i)
	{
		if(freq.count(s2[i]) == 0)
		{
			return false;
		}
		else
		{
			freq[s2[i]]--;
			if(freq[s2[i]] == 0)
			{
				num_checked++;
			}

			if(num_checked == num_unique && i == (s2.size()-1))
			{
				return true;
			}
		}
	}

	return false;
}

void anagrams_run()
{
	cout << anagrams("pear", "reap") << endl;
	cout << anagrams("hello", "haiz") << endl;
	cout << anagrams("dictionary", "indicatory") << endl;
}
