/*
ID: rajorsh2
PROG: milk
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

struct vendor
{
	int cost;
	int qty;
};

bool comp(vendor v1, vendor v2)
{
	return v1.cost < v2.cost;
}

int main() 
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	istringstream isnm(readline(fin));
	int N, M;
	isnm>>N>>M;

	vector<vendor> vendors;
	while(M--)
	{
		vendor v;
		istringstream cq(readline(fin));
		cq>>v.cost>>v.qty;
		vendors.push_back(v);
	}

	sort(vendors.begin(), vendors.end(), comp);
	int cost = 0;

	for(int i=0; i<vendors.size(); i++)
	{
		if(N == 0)
			break;

		if(N < vendors[i].qty)
		{
			cost += N*vendors[i].cost;
			N = 0;
		}
		else
		{
			cost += vendors[i].qty * vendors[i].cost;
			N -= vendors[i].qty;
		}
	}

	fout<<cost<<endl;
	return 0;
}