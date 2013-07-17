#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxsubseqsum(vector<int>& v)
{
	vector<int> m(v.size(), 0);
	m[0] = v[0];
	for(size_t i=1; i<v.size(); i++)
	{
		m[i] = max(m[i-1] + v[i], v[i]);
	}		
	return *max_element(m.begin(), m.end());
}

int main()
{
	int arr[] = { 2, -2, 4, -5, 1, 0, 6, -3, 2, 1, -5, 0 };
	vector<int> v(arr, arr+12);
	cout<<maxsubseqsum(v)<<endl;
	return 0;
}