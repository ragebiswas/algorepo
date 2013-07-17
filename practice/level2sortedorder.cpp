#include <iostream>
#include <vector>
using namespace std;

void level2sorted(vector<int>& v, int start, int end)
{
	if(start > end) 
		return;
	level2sorted(v, start*2+1, end);
	cout<<v[start]<<" ";
	level2sorted(v, start*2+2, end);
}

int main()
{
	int arr[] = { 4, 2, 5, 1, 3 };
	vector<int> v(arr, arr+5);
	level2sorted(v, 0, 4);
	return 0;
}