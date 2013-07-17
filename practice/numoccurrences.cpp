#include <iostream>
#include <vector>
using namespace std;

int num_occurrences(vector<int>& a, int n)
{
	int firstpos = a.size();
	int lastpos = 0;
	int low = 0;
	int high = a.size() - 1;
	
	// find first occurrence of n
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(a[mid] < n)
		{
			low = mid+1;
		}
		else if(a[mid] > n)
		{
			high = mid-1;
		}
		else
		{
			if(mid < firstpos)
				firstpos = mid;
			high = mid-1;
		}
	}
	
	low = firstpos;
	high = a.size() - 1;
	
	// find last occurrence of n
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(a[mid] < n)
		{
			low = mid+1;
		}
		else if(a[mid] > n)
		{
			high = mid-1;
		}
		else
		{
			if(mid > lastpos)
				lastpos = mid;
			low = mid+1;
		}
	}
	
	return lastpos-firstpos+1;
}

int main()
{
	int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 6 };
	vector<int> v(arr, arr+12);
	cout<<num_occurrences(v, 1)<<endl;
	cout<<num_occurrences(v, 2)<<endl;	
	return 0;
}