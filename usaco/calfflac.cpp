/*
ID: rajorsh2
PROG: calfflac
LANG: C++
*/

#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int getpalsz(const string& str, int left, int right, int& b, int& e)
{
	int palsz = 0;
	int start, end, sz;
	start = left;
	end = right;
	sz = str.size();
	b = e = 0;

	while(start >= 0 && !isalpha(str[start])) 
	{ 
		start--; 
	} 
	
	while(end < sz && !isalpha(str[end]))
	{ 
		end++; 
	}   

	while(str[start] == str[end])
	{
		if(str[start] != str[end])
			break;

		b = start;
		e = end;

		palsz+= ( start == end ? 1 : 2 );

		do { start--; } while(start >= 0 && !isalpha(str[start]));
		do { end++; }   while(end < sz && !isalpha(str[end]));

		if(start < 0 || end >= sz)
			break;
	}

	return palsz;
}


void findlongest(const string& strorig, ofstream& fout)
{
	string str = strorig;
	transform(str.begin(), str.end(), str.begin(), ::tolower);

	int sz = str.size();
	int maxstart, maxend;
	int maxpalsz = 1;
	int palsz1, palsz2;
	int s1, e1, s2, e2;

	maxstart = maxend = 0;

	for(int i=1; i<sz; i++)
	{
		//cerr<<"\nat index "<<i<<endl;

		// see if there's a possibility of a palindrome CENTERING at i
		palsz1 = getpalsz(str, i, i, s1, e1);
		palsz2 = getpalsz(str, i-1, i, s2, e2);

		if(palsz1 > maxpalsz)
		{
			maxpalsz = palsz1;
			maxstart = s1;
			maxend = e1;
		}
		
		if(palsz2 > maxpalsz)
		{
			maxpalsz = palsz2;
			maxstart = s2;
			maxend = e2;
		}

	}

	fout<<maxpalsz<<endl;
	fout<<strorig.substr(maxstart, maxend-maxstart+1)<<endl;

}


int main()
{
	ifstream infile("calfflac.in");
	ofstream fout("calfflac.out");

	string str;
	string line;

	while(getline(infile, line))
	{
	str += (line + "\n");
	}

	findlongest(str, fout);	
	return 0;
}