#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	ifstream fin(argv[1]);
	int idx, z = 'z', sum;
	string bwt;
	while(fin>>idx>>bwt)
	{
		int sz = bwt.size(), sum = 0;
		vector<int> c(z+1, 0), p(sz, 0);
		string in(sz, ' ');
		for(int i=0; i<sz; ++i)
		{
			p[i] = c[bwt[i]];
			c[bwt[i]]++;
		}
		for(int i='A'; i<='z'; ++i)
		{
			sum += c[i];
			c[i] = sum-c[i];
		}
		int j = idx;
		for(int i=sz-1; i>=0; i--)
		{
			in[i] = bwt[j];
			j = p[j] + c[bwt[j]];
		}
		cout<<in<<"\n";
	}
}
