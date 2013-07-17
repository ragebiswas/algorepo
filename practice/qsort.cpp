#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int i)
{
	cout<<i<<" ";
}

int partition(vector<int>& v, int p, int q)
{
	int r = p;
	int pe = v[p];
	p++;
	
	while(p <= q)
	{
		while(v[p] <= pe)
			p++;

		while(v[q] > pe)
			q--;
		
		if(p < q)
			swap(v[p], v[q]);
	}	
	
	swap(v[r], v[q]);
	return q;
}

void quicksort(vector<int>& v, int p, int q)
{
	if(p >= q)
		return;
		
	int r = partition(v, p, q);
	quicksort(v, p, r-1);
	quicksort(v, r+1, q);	
}


int main()
{
	int arr1[] = { 2, -4, -6, -3, 12, 10, 5, 0, 0, -5 };
	int arr2[]   = { 5, 9, -2, -3, 8, 3, 1, 7, 6, 0 };
	vector<int> v1(arr1, arr1+10);
	vector<int> v2(arr2, arr2+10);
	
	quicksort(v1, 0, v1.size() - 1);
	for_each(v1.begin(), v1.end(), print);
	cout<<endl;
	
	quicksort(v2, 0, v2.size() - 1);
	for_each(v2.begin(), v2.end(), print);
	cout<<endl;
	
	return 0;
}