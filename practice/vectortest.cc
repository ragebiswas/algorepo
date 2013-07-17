/*
 * vectortest.cc
 *
 *  Created on: Apr 3, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void populate(vector<int>& v)
{
	v.push_back(1);
	v.push_back(11);
}

void vectortest_run()
{
	vector<int> v;
	populate(v);
	for(size_t i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<",";
	}
}
