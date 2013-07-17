#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() 
{
	int n, q;
	cin>>n>>q;
	vector<int> rows(n, 0);
	vector<int> cols(n, 0);
	string line;
	getchar();

	while(q--) 
	{
		getline(cin, line);
		istringstream iss(line);
		string type;
		int d, c;
		iss>>type>>d>>c;
		if(type == "RowAdd") 
			rows[d-1] += c;
		else
			cols[d-1] += c;
	}

	int mr = 0, mc = 0;
	for(int i=0; i<n; i++)
		mr = max(mr, rows[i]);

	for(int j=0; j<n; j++)
		mc = max(mc, cols[j]);

	cout<<mr+mc<<endl;
	return 0;
}