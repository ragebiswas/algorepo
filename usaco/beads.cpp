/*
ID: rajorsh2
PROG: beads
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


int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	readline(fin);
	string beads = readline(fin);
	int gmax = 0;

	for(size_t pos = 0; pos<beads.size(); pos++)
	{
		// try right part
		char rightcol = beads[pos];
		int j = pos;
		int rightcount = 1;
		vector<bool> visited(beads.size(), false);
		visited[pos] = true;

		while(1)
		{

			if((j+1)%beads.size() == pos) 
				break;

			j = (j+1)%beads.size();

			if(rightcol == 'w' && beads[j] != 'w')
			{
				rightcol = beads[j];
			}
			
			if(beads[j] == rightcol || beads[j] == 'w')
			{
				rightcount++;
				visited[j] = true;
			}
			else
				break;
		}

		// try left part
		char leftcol = ' ';
		int lpos;
		if(pos > 0) 
			lpos = pos-1;
		else 
			lpos = beads.size() - 1;
		j = lpos;
		leftcol = beads[j]; 
		int leftcount = 0;

		if(!visited[j])
		{
			leftcount = 1;
			while(1)
			{
				j--;
				if(j < 0) 
					j = beads.size() - 1;

				if(j == lpos) 
					break;

				if(visited[j]) 
					break;

				if(leftcol == 'w' && beads[j] != 'w')
					leftcol = beads[j];

				if(beads[j] == leftcol || beads[j] == 'w')
					leftcount++;
				else 
					break;
			}
		}

		gmax = max( gmax, (leftcount + rightcount) );

	}

	fout<<gmax<<endl;
	return 0;
}