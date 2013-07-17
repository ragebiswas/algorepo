#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

void print(int i)
{
	cout<<i<<" ";
}

void merge(vector<int>& v, int l, int m, int r)
{
	vector<int> buf1(v.begin() + l, v.begin() + m + 1);
	vector<int> buf2(v.begin() + m + 1, v.begin() + r + 1);
	
	int buf1ptr = 0, buf2ptr = 0;
	int p = l;
	
	while(buf1ptr < buf1.size() && buf2ptr < buf2.size())
	{
		if(buf1[buf1ptr] < buf2[buf2ptr])
		{
			v[p++] = buf1[buf1ptr++];
		}
		else
		{
			v[p++] = buf2[buf2ptr++];
		}
	}
	
	if(buf1ptr < buf1.size())
	{
		while(buf1ptr < buf1.size())
		{
			v[p++] = buf1[buf1ptr++];
		}
	}
	
	if(buf2ptr < buf2.size())
	{
		while(buf2ptr < buf2.size())
		{
			v[p++] = buf2[buf2ptr++];
		}
	}
}

void mergesort(vector<int>& v, int l, int r)
{
	if(l >= r)
		return;
		
	int m = (l+r)/2;
	mergesort(v, l, m);
	mergesort(v, m+1, r);
	merge(v, l, m, r);
}

int main()
{
	int arr[] = { 3, 2, 1, 0, 9, 8, 3, 4, 12, -2 };
	vector<int> v(arr, arr+10);
	cout<<"Sorting: ";
	for_each(v.begin(), v.end(), print); 
	cout<<endl;
	
	mergesort(v, 0, v.size()-1);
	
	cout<<"Sorted : ";	
	for_each(v.begin(), v.end(), print);
	cout<<endl;
	
	return 0;
}
	 