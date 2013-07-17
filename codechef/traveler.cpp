#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <cstdlib>

#define MAX 51

using namespace std;

int main()
{
	int n, t, k;
	string tmp, c1, c2, d;
	getline(cin,tmp);
	n = atoi(tmp.c_str());

	string c[MAX];
	int g[MAX][MAX];
	map<string, int> m;

	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
			g[i][j] = 0;

	getline(cin, tmp);
	istringstream iss(tmp);
	for(int i=0; i<n; ++i)
	{
		iss>>tmp;
		c[i] = tmp;
		m[tmp] = i;
	}

	getline(cin, tmp);
	t = atoi(tmp.c_str());
	while(t--)
	{
		getline(cin, tmp);
		istringstream iss(tmp);
		iss>>c1>>c2>>d;
		g[m[c1]][m[c2]] = atoi(d.c_str());
	}

	getline(cin, tmp);
	t = atoi(tmp.c_str());
	while(t--)
	{
		getline(cin, tmp);
		istringstream iss(tmp);
		iss>>tmp;
		k = atoi(tmp.c_str());
		vector<bool> seen(n, false);
		string last = "";
		int d = 0;

		while(k--)
		{
			iss>>tmp;
			if(m.find(tmp) == m.end())
				{ d = -1; cout<<"ERROR\n"; break; }
			
			if(last != "" && g[m[last]][m[tmp]] == 0)
				{ d = -1; cout<<"ERROR\n"; break; }

			if(seen[m[tmp]])
				{ d = -1; cout<<"ERROR\n"; break; }

			if(last != "")
				d += g[m[last]][m[tmp]];
			
			last = tmp;
			seen[m[tmp]] = true;			
		}

		if(d >= 0)
			cout<<d<<endl;
	}


	return 0;
}
	
