#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define LEN 1000000
#define INPUT "A-large.in"


static void print(string i)
{
	cout<<i<<endl;
}

static string readline(ifstream& ifs)
{
	char line[LEN];
	ifs.getline(line, LEN);
	string s = line;
	return s;
}

static string int_to_string(long i)
{
	ostringstream oss;
	oss<<i;
	return oss.str();
}

static long string_to_int(string s)
{
	istringstream iss(s);
	int i;
	iss>>i;
	return i;
}

struct butt
{
	char robot;
	int pos;
	bool done;
};

butt& getnextmove(vector<butt>& butts, int start, char r)
{
	butt &p = butts[start];
	for(size_t i=start+1 ; i< butts.size(); i++)
		if(butts[i].robot == r)
			return butts[i];
	return p;
}

int main()
{

	ifstream ifs;
	ifs.open(INPUT);

	int ncases = 0;
	string ncases_str = readline(ifs);
	istringstream iss(ncases_str);
	iss>>ncases;

	for(int nc=0; nc<ncases; nc++)
	{
		int time = 0;

		int opos = 1;
		int bpos = 1;

		string tc = readline(ifs);
		istringstream iss(tc);

		int num;
		iss >> num;
		string s;

		vector<butt> butts;

		for(int k=0; k<num; k++)
		{
			char r;
			iss>>r;

			int p;
			iss>>p;

			butt b;
			b.robot = r;
			b.pos = p;
			b.done = false;
			butts.push_back(b);
		}

		int t = 0; // time

		for(size_t i = 0; i < butts.size(); i++)
		{
			butt curmove = butts[i];

			while(!curmove.done)
			{
				if(curmove.robot == 'O')
				{
					int tpos = curmove.pos;
					int tt = abs(curmove.pos - opos) + 1;

					t += tt;
					opos = tpos;
					curmove.done = true;

					butt nextbmove = getnextmove(butts, i, 'B');
					if(nextbmove.robot == 'B') // else no more moves for 'B'
					{
						int reqmoves = (nextbmove.pos - bpos);
						if(reqmoves > 0)
						{
							int btt = min(tt, reqmoves);
							while(btt--) bpos++;
						}
						else if(reqmoves < 0)
						{
							int btt = min(tt,abs(reqmoves));
							while(btt--) bpos--;
						}
						// else it can just wait where it is
					}
				}
				else
				{
					int tpos = curmove.pos;
					int tt = abs(curmove.pos - bpos) + 1;

					t += tt;
					bpos = tpos;
					curmove.done = true;

					butt nextomove = getnextmove(butts, i, 'O');
					if(nextomove.robot == 'O') // else no more moves for 'O'
					{
						int reqmoves = (nextomove.pos - opos);
						if(reqmoves > 0)
						{
							int ott = min(tt, reqmoves);
							while(ott--) opos++;
						}
						else if(reqmoves < 0)
						{
							int ott = min(tt,abs(reqmoves));
							while(ott--) opos--;
						}
						// else it can just wait where it is
					}

				}
			}
		}

		cout<<"Case #"<<nc+1<<": "<<t<<endl;
	}

	return 0;
}
