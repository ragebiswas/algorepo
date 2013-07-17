/*
 * uniquechars.cc
 * 	Careercup pdf problem 1.1
 *
 *  Created on: Mar 29, 2011
 *      Author: biswasra
 */
#include <string>
#include <iostream>

bool unique(std::string s)
{
	for (unsigned i = 0; i < s.length(); ++i)
	{
		for (unsigned j = 0; j < s.length(); ++j)
		{
			if (i != j && s[i] == s[j])
			{
				return false;
			}
		}
	}
	return true;
}

void uniquechars_run()
{
	std::cout << unique("abb");
}
