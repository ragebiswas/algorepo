#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int idx;
	string bwt;
	ifstream fin(argv[1]);
	while(fin>>idx>>bwt)
	{
		int sz = bwt.size();
		string row(sz, '|');
		vector<string> m(sz, row);
		int col = sz - 1;
		for(int i=0; i<sz; ++i, --col)
		{
			for(int j=0; j<sz; ++j)
				m[j][col] = bwt[j];
			sort(m.begin(), m.end());		
		}
		cout<<m[idx]<<"\n";
	}
    return 0;
}
