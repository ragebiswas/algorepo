/*
ID: rajorsh2
PROG: milk2
LANG: C++
*/

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

#define LEN 1000000

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

bool bitmap[1000000] = {false};

int main()
{
	ifstream infile("milk2.in");
	ofstream outfile("milk2.out");

	int N = string_to_int(readline(infile));	
	vector<int> starts;
	vector<int> ends;
	
	while(N--)
	{
		string s = readline(infile);
		int start, end;
		istringstream iss(s);
		iss>>start>>end;
		
		starts.push_back(start);
		ends.push_back(end);

		for(int t=start; t<end; t++)
			bitmap[t] = true;
	}

	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end(), greater<int>());

	bool inmilking = false;
	int maxmilking = 0;
	int maxnonmilking = 0;
	int milking = 0;
	int nonmilking = 0;

	for(int i=starts[0]; i<ends[0]; i++)
	{
		if(bitmap[i])
		{
			if(inmilking)
			{
				milking++;
			}
			else
			{
				inmilking = true;
				maxmilking = max(milking, maxmilking);
				milking = 1;
			}
		}
		else
		{
			if(inmilking)
			{
				inmilking = false;
				maxnonmilking = max(nonmilking, maxnonmilking);
				nonmilking = 1;
			}
			else
			{
				nonmilking++;
			}
		}
	}

	maxmilking = max(milking, maxmilking);
	maxnonmilking = max(nonmilking, maxnonmilking);

	outfile<<maxmilking<<" "<<maxnonmilking<<endl;
	return 0;
}
