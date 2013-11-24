/*
ID: rajorsh2
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <fstream>
using namespace std;

struct frac_comparator
{
	bool operator() (const pair<int, int>& f1, const pair<int, int>& f2)
	{
		return f1.first * f2.second < f2.first * f1.second;
	}
};


int main()
{
    ifstream cin("frac1.in");
    ofstream cout("frac1.out");
    
	int i, n;
	cin >> n;    

	map<pair<int, int>, bool, frac_comparator> m;
	vector<pair<int, int> > v;

	for (int denom = 1; denom <= n; denom++) {
		for (int num = 0; num <= denom; num++) {
			pair<int, int> p = make_pair(num, denom);
			if (m.find(p) == m.end()) {
				v.push_back(p);
				m[p] = true;
			}
		}
	}

	sort(v.begin(), v.end(), frac_comparator());

	for (i = 0; i < v.size(); i++)
		cout << v[i].first << "/" << v[i].second << endl;

	return 0;
}