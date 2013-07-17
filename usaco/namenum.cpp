/*
ID: rajorsh2
PROG: namenum
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

static char getnum(char alpha)
{
	switch(alpha)
	{
	case 'A':
	case 'B':
	case 'C':
		return '2';
		break;
	case 'D':
	case 'E':
	case 'F':
		return '3';
		break;
	case 'G':
	case 'H':
	case 'I':
		return '4';
		break;
	case 'J':
	case 'K':
	case 'L':
		return '5';
		break;
	case 'M':
	case 'N':
	case 'O':
		return '6';
		break;
	case 'P':
	case 'R':
	case 'S':
		return '7';
		break;
	case 'T':
	case 'U':
	case 'V':
		return '8';
		break;
	case 'W':
	case 'X':
	case 'Y':
		return '9';
		break;
	default:
		return '-';
		break;
	}
}


vector<string> solve(string& t9, const vector<string>& words)
{
	vector<string> res;

	for(size_t i=0; i<words.size(); i++)
	{
		bool possible = true;
		string word = words[i];


		for(size_t j=0; j<t9.size(); j++)
		{
			if(getnum(word[j]) != t9[j])
			{
				possible = false;
				break;
			}
		}

		if(possible)
			res.push_back(words[i]);
	}

	return res;
}


int main() 
{
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream dictfile("dict.txt");

	string t9 = readline(fin);
	int sz = t9.size();

	vector<string> words;
	map<string, bool> wmap;

	string word;

	while(!dictfile.eof())
	{
		dictfile>>word;
		if(word.size() == sz)
		{
			words.push_back(word);			
			wmap[word] = true;
		}
	}

	vector<string> res = solve(t9, words);
    
    if(!res.empty())
	{
		sort(res.begin(), res.end());
	
		for(size_t i=0; i<res.size(); i++)
			fout<<res[i]<<endl;
	}
	else
	{
		fout<<"NONE"<<endl;
	}

	return 0;
}