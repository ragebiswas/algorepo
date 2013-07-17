#include <string>
#include <fstream>
#include <iostream>
using namespace std;

static string p1 = "1,1,1,1", p2 = "2,2,2,2";
static string ringbuf[4];

int main(int argc, char** argv)
{
	ifstream fin(argv[1]);	
	int i = 0, k = 0, sz = 0, ended = 1;

	getline(fin, ringbuf[i++]);
	sz = ringbuf[0].size();

	while(getline(fin, ringbuf[i]))
	{
		if(ringbuf[i].empty())
			continue;

		if(ringbuf[i].find(p1) != string::npos)
		{
			cout<<"1\n";
			return 0;
		}
		if(ringbuf[i].find(p2) != string::npos)
		{
			cout<<"2\n";
			return 0;
		}

		if(ringbuf[i].find("0") != string::npos)
			ended = 0;

		i = (i+1)%4;

		for(k = 0; k<sz; ++k)
		{
			if(ringbuf[0][k] == '1' && ringbuf[1][k] == '1' && ringbuf[2][k] == '1' && ringbuf[3][k] == '1')
			{
				cout<<"1\n";
				return 0;
			}
			else if(ringbuf[0][k] == '2' && ringbuf[1][k] == '2' && ringbuf[2][k] == '2' && ringbuf[3][k] == '2')
			{
				cout<<"2\n";
				return 0;
			}
		}
	}

	if(ended)
		cout<<"draw\n";
	else 
		cout<<"play\n";

	return 0;
}