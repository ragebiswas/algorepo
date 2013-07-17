/*
ID: rajorsh2
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
#define LEN 1000000

static void print(string& s)
{
	cout<<s<<endl;
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

char cmap[21];

void initmap()
{
	for(int i=0; i<10; i++)
		cmap[i] = '0'+i;

	for(int i=10, j=0; i<=20; i++, j++)
		cmap[i] = 'A'+j;
}

bool ispalindrome(string str)
{
	int sz = str.size();
	for(int i=0; i<sz; i++)
		if(str[i] != str[sz-i-1])
			return false;
	return true;
}

string decimaltobase(int num, int base)
{
	string res = "";
	string es = "";

	while(num)
	{
		res = es + cmap[num%base] + res;
		num /= base;
	}

	return res;
}


int main() 
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int B = string_to_int(readline(fin));

	initmap();

	for(int n=1; n<=300; n++)
	{
		int sq = n*n;
		if(ispalindrome(decimaltobase(sq, B)))
			fout<<decimaltobase(n,B)<<" "<<decimaltobase(sq,B)<<endl;
	}

	return 0;
}