#include <iostream>
#include <vector>

using namespace std;

int maxsubseqsum(vector<int>& v)
{
	int maxendinghere = 0;
	int globalmax = 0;
	
	for(size_t i=0; i<v.size(); i++)
	{
		maxendinghere = max(maxendinghere + v[i], 0);
		globalmax = max(globalmax, maxendinghere);
	}
		
	return globalmax;
}

int main()
{
	int arr[] = { 2, -2, 4, -5, 1, 0, 6, -3, 2, 1, -5, 0 };
	vector<int> v(arr, arr+12);
	cout<<maxsubseqsum(v)<<endl;
	return 0;
}