#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int main()
{
	int ncases, k, r;
	cin>>ncases;

	while(ncases--)
	{
		int dividend = 103993;
		int divisor = 33102;
		cin>>k;
		(k>0) ? cout<< "3." : cout << "3";
		dividend = dividend - (divisor*3);
		for(int t=1; t<=k; t++)
		{
			dividend *= 10;
			r = dividend/divisor;
			cout<<r;
			dividend = dividend - (divisor*r);
		}
		cout<<endl;

	}

	return 0;
}