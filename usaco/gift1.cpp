/*
ID: rajorsh2
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

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

struct person
{
	string name;
	long startmoney;
	long endmoney;
};

person& findperson(vector<person>& persons, string name)
{
	for(size_t i=0; i<persons.size(); i++)
	{
		if(persons[i].name == name)
			return persons[i];
	}
}


int main()
{
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");

	int numpersons = string_to_int(readline(fin));
	vector<person> persons;

	for(int i=0; i<numpersons; i++)
	{
		person p;
		p.startmoney = 0;
		p.endmoney = 0;
		p.name = readline(fin);
		persons.push_back(p);
	}

	for(int i=0; i<numpersons; i++)
	{
		string pname = readline(fin);
		person &p = findperson(persons, pname);

		string numbers = readline(fin);
		istringstream iss(numbers);
		int amt, ng;
		iss>>amt>>ng;

		if(amt == 0 || ng == 0) 
			continue;

		p.startmoney = amt;
		int share = amt/ng;
		p.endmoney += (p.startmoney - ng*share);

		for(int j=0; j<ng; j++)
		{
			string gname = readline(fin);
			person &g = findperson(persons, gname);
			g.endmoney += share;
		}
	}


	for(int k=0; k<numpersons; k++)
	{
		fout<<persons[k].name<<" "<<persons[k].endmoney-persons[k].startmoney<<endl;
	}


	return 0;
}

