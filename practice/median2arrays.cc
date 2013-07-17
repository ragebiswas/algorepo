/*
 * median2arrays.cc
 *
 *  Created on: Apr 7, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_median_easy(vector<int> v1, vector<int> v2)
{
	vector<int>::iterator i1 = v1.begin();
	vector<int>::iterator i2 = v2.begin();
	vector<int>::iterator it;

	int count = 0;
	int medianindex = (v1.size() + v2.size()) / 2;

	do
	{
		if ((*i1) < (*i2))
		{
			it = i1;
			++i1;
		}
		else
		{
			it = i2;
			++i2;
		}

		++count;

	} while (count < medianindex);

	return *it;
}


int get(int idx)
{

}


void set(int idx, int val)
{

}

int find_median_notsoeasy(vector<int> v1, vector<int> v2)
{

}


void median2arrays_run()
{
	int arr1[] =
	{ 10, 20, 50, 100 };
	vector<int> v1(arr1, arr1 + 4);

	int arr2[] =
	{ 12, 14, 21, 22 };
	vector<int> v2(arr2, arr2 + 4);

	cout << "Median: " << find_median_easy(v1, v2);
}
