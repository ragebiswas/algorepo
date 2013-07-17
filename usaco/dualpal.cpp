/*
ID: rajorsh2
PROG: dualpal
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

static char cmap[21];

static void initmap()
{
	for(int i=0; i<10; i++)
		cmap[i] = '0'+i;

	for(int i=10, j=0; i<=20; i++, j++)
		cmap[i] = 'A'+j;
}

static bool ispalindrome(string str)
{
	int sz = str.size();
	for(int i=0; i<sz; i++)
		if(str[i] != str[sz-i-1])
			return false;
	return true;
}

static string decimaltobase(int num, int base)
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


bool possible(int s)
{
	int numpal = 0;
	for(int b=2; b<=10; b++)
	{
		if(ispalindrome(decimaltobase(s,b)))
		{
			numpal++;
		}

		if(numpal == 2)
			return true;
	}

	return false;
}

int main() 
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	initmap();

	int N, S;
	string ns = readline(fin);
	istringstream isns(ns);
	isns>>N>>S;

	S++;

	while(N)
	{
		if(possible(S))
		{
			fout<<S<<endl;
			N--;
		}
		S++;
	}

	return 0;
}