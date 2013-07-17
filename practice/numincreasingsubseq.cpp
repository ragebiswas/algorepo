#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int num_increasing_subsequences(vector<int>& v)
{
	vector<int> dp(v.size(), 1);
	for(size_t i=1; i<v.size(); i++)
	{
		for(size_t j=0; j<i; j++)
		{
			if(v[i] >= v[j])
				dp[i] = dp[i] + dp[j];
		}
	}
	
	return accumulate(dp.begin(), dp.end(), 0);
}

int main()
{
	int arr[] = { 1, 3, 2, 4 };
	vector<int> v(arr, arr+4);
	cout<<"Number of increasing subsequences: "<<num_increasing_subsequences(v)<<endl;
	return 0;
}