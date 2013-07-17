#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

size_t leftsumeqrightsum(const vector<int>& v)
{
	int sum = accumulate(v.begin(), v.end(), 0);
	
	int lsum = 0, rsum = sum;
	for(int i = 0; i<v.size()-1; i++)
	{
		if(lsum + v[i] == rsum - v[i])
			return i+1;
		lsum += v[i];
		rsum -= v[i];
	}
	
	return -1;
}

int main()
{
	int arr[] = { 30, 20, 10, 15, 15, 25, 115 };
	vector<int> v(arr, arr+7);
	cout<<"Index where left sum = right sum: "<<leftsumeqrightsum(v)<<endl;
	return 0;
}
	