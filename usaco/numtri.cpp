/*
ID: rajorsh2
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream cin("numtri.in");
	ofstream cout("numtri.out");

	int n;
	cin>>n;
	
	vector<int> _r(n, 0);
	vector< vector<int> > arr(n, _r);
	
	int r=1;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<r; j++)
			cin>>arr[i][j];
		r++;
	}
	
	int s=n-1;
	for(int r=n-2; r>=0; r--)
	{
		for(int i=0; i<s; i++)
		{
			arr[r][i] += max(arr[r+1][i], arr[r+1][i+1]);
		}
	}
	
	cout<<arr[0][0]<<endl;
	return 0;
}