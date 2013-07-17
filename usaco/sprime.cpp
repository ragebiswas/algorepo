/*
ID: rajorsh2
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool isprime(int n)
{
	if(n==2)
		return true;
		
	if(n==1 || n%2==0)
		return false;		
		
	for(int k=3; k*k <= n; k+=2)
		if(n%k==0)
			return false;
	
	return true;
}

vector<int> answers;

void solve(int n, int depth)
{
	if(depth<0 || !isprime(n)) 
		return;
		
	if(depth==0)
	{
		answers.push_back(n);
		return;
	}
	
	for(int d=1; d<=9; d+=2)
		solve(n*10+d, depth-1);
}

int main()
{
	int n;
	
	ifstream cin("sprime.in");
	ofstream cout("sprime.out");
	cin>>n;
	
	for(int i=1; i<=9; i++)
		solve(i, n-1);
		
	for(int i=0; i<answers.size(); i++)
		cout<<answers[i]<<endl;
	
	return 0;
}