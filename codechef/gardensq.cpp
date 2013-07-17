#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	int nc, r, c;
	cin>>nc;
	char m[51][51];

	while(nc--)
	{
		cin>>r>>c;
		int mp = max(r,c);
		int cnt = 0;

		string line;
		for(int i=0; i<r; i++)
		{
			cin>>line;
			for(int j=0; j<c; j++)
				m[i][j] = line[j];
		}

		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				for(int k = 1; k<=mp; k++)
				{
					char col = m[i][j];
					if((j+k >= c) || m[i][j+k] != col)
						continue;

					if((i+k >= r) || m[i+k][j] != col)
						continue;

					if(m[i+k][j+k] != col)
						continue;

					cnt++;
				}
			}
		}

		cout<<cnt<<endl;
	}
}