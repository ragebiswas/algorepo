#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

string p1 = "1,1,1,1", p2 = "2,2,2,2";
string ringbuf[4], *ptr[4];

inline void onewins() { cout<<"1\n"; exit(0); }
inline void twowins() { cout<<"2\n"; exit(0); }

int main(int argc, char **argv)
{
	ifstream fp(argv[1]);	
	int i = 0, k = 0, l = 0, sz = 0, ended = 1;

	getline(fp, ringbuf[0]);
	sz = ringbuf[i++].size();
	ptr[3] = &ringbuf[0];

	while(getline(fp, ringbuf[i]))
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

		ptr[3] = &ringbuf[i];
		ptr[0] = &ringbuf[(i+1)%4];
		ptr[1] = &ringbuf[(i+2)%4];
		ptr[2] = &ringbuf[(i+3)%4];

		i = (i+1)%4;
		l++;

		if(l < 3)
			continue;

		for(k = 0; k<sz; ++k)
		{
			if((*ptr[0])[k] == '1' && (*ptr[1])[k] == '1' && (*ptr[2])[k] == '1' && (*ptr[3])[k] == '1')
				onewins();

			if((*ptr[0])[k] == '2' && (*ptr[1])[k] == '2' && (*ptr[2])[k] == '2' && (*ptr[3])[k] == '2')
				twowins();

			if(k + 6 < sz)
			{
				if((*ptr[0])[k] == '1' && (*ptr[1])[k+2] == '1' && (*ptr[2])[k+4] == '1' && (*ptr[3])[k+6] == '1')
					onewins();

				if((*ptr[0])[k] == '2' && (*ptr[1])[k+2] == '2' && (*ptr[2])[k+4] == '2' && (*ptr[3])[k+6] == '2')
					twowins();	
			}

			if(k >= 6)
			{
				if((*ptr[0])[k] == '1' && (*ptr[1])[k-2] == '1' && (*ptr[2])[k-4] == '1' && (*ptr[3])[k-6] == '1')
					onewins();

				if((*ptr[0])[k] == '2' && (*ptr[1])[k-2] == '2' && (*ptr[2])[k-4] == '2' && (*ptr[3])[k-6] == '2')
					twowins();	
			}
		}
	}

	if(ended)
		cout<<"draw\n";
	else 
		cout<<"play\n";

	fp.close();
	return 0;
}