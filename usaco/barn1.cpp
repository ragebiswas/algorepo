/*
ID: rajorsh2
PROG: barn1
LANG: C++
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() 
{
	string line;
	ifstream infile("barn1.in");
	ofstream ofile("barn1.out");

	getline(infile, line);
	istringstream iss(line);
	int M, S, C;
	iss>>M>>S>>C;
	vector<int> cows(C);
	for(int i=0; i<C; i++) {
		getline(infile, line);
		istringstream iss(line);
		iss>>cows[i];
	}

	sort(cows.begin(), cows.end());
	int nboards = cows.size();
	vector<int> gaps;

	for(int i=0; i<cows.size()-1; i++) {
		gaps.push_back(cows[i+1]-cows[i]);
	}

	sort(gaps.begin(), gaps.end());
	int ncovered = nboards;

	int i = 0;
	while(nboards > M) {
		ncovered += (gaps[i++]-1);
		nboards--;
	}

	ofile << ncovered << endl;

	return 0;
}