/*
ID: rajorsh2
PROG: pprime
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

vector<int> primes;

void test(int p)
{
	if(isprime(p)) 
		primes.push_back(p);
}

void try1()
{
	for(int i=3; i<=9; i++)
		test(i);
}

void try2()
{
	primes.push_back(11);
}

void try3()
{
	for(int i=1; i<=9; i++)
		for(int j=0; j<=9; j++)
		{
			// iji
			int p = i*100 + j*10 + i;
			test(p);
		}

}

void try5()
{
	for(int i=1; i<=9; i++)
		for(int j=0; j<=9; j++)
			for(int k=0; k<=9; k++)
			{
				// ijkji
				int p = i*10000+j*1000+k*100+j*10+i;
				test(p);
			}	
}

void try7()
{
	for(int i=1; i<=9; i++)
		for(int j=0; j<=9; j++)
			for(int k=0; k<=9; k++)
				for(int l=0; l<=9; l++)
				{
					// ijklkji
					int p = i*1000000+j*100000+k*10000+l*1000+k*100+j*10+i;
					test(p);
				}
}

void try9()
{
	for(int i=1; i<=9; i++)
		for(int j=0; j<=9; j++)
			for(int k=0; k<=9; k++)
				for(int l=0; l<=9; l++)
					for(int m=0; m<=9; m++)
					{
						// ijklmlkji
						int p = i*100000000+j*10000000+k*1000000+l*100000+m*10000+l*1000+k*100+j*10+i; 
						test(p);
					}
}

int main()
{
	int a, b;
	
	ifstream cin("pprime.in");
	ofstream cout("pprime.out");
	
	cin>>a>>b;
	
	try1();
	try2();
	try3();
	try5();
	try7();
	try9();
	
	sort(primes.begin(), primes.end());
	for(int i=0; i<primes.size(); i++)
	{
		if(primes[i] >= a && primes[i] <= b)
			cout<<primes[i]<<endl;
	}
	
	return 0;
}