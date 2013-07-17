#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int longest_ap(vector<int>& v)
{
	int maxdiff = *max_element(v.begin(), v.end()) 
					- *min_element(v.begin(), v.end());
	
	vector<int> dpelem(maxdiff + 1, 1);
	vector<vector<int> > dp(v.size(), dpelem);
	
	for(size_t i=1; i<v.size(); i++)
	{
		for(int d=1; d<=maxdiff; d++)
		{
			for(size_t j=0; j<i; j++)
			{
				if(v[i] - v[j] == d)
				{
					dp[i][d] = dp[j][d]+1;
				}
			}
		} 
	}
	
	int m = 0;
	for(size_t i=0; i<v.size(); i++)
	{
		m = max(m, *max_element(dp[i].begin(), dp[i].end()));
	}
	
	return m;
}

int main()
{
	int arr[] = { 1, 8, 9, 3, 5, 2, 1, 7, 9, 10 };
	vector<int> v(arr, arr+10);
	cout<<"Longest Arithmetic Progression: "<<longest_ap(v)<<endl;
	return 0;
}