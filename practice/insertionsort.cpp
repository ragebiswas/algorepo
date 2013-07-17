#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int i)
{
	cout<<i<<" ";
}

void insertion_sort(vector<int>& v)
{
	for(size_t i=0; i<v.size()-1; i++)
	{
		size_t minj = i;
		int minrest = v[i];
		for(size_t j=i+1; j<v.size(); j++)
		{
			if(v[j] < minrest)
			{
				minrest = v[j];
				minj = j;
			}
		}
		if(minj != i)
			swap(v[i], v[minj]);
	}
}

int main()
{
	int arr[] = { -5, 3, 4, 9, 2, -4 };
	vector<int> v(arr, arr+6);
	insertion_sort(v);
	for_each(v.begin(), v.end(), print);
	return 0;
}
	