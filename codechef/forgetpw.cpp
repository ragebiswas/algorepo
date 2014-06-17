// Codechef June 2014: Forgot Password
// Easy coding 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<char, char> rule;

string simplify(const string& input) 
{
	string ret = input;
	int last = ret.size() - 1;
	while (last >= 0 && ret[last] == '0') {
		last--;
	}
	if (last > 0 && ret.find('.') != string::npos && ret.find('.') <= last) {
		ret = ret.substr(0, last + 1);
	}
	if (ret[ret.size() - 1] == '.') {
		ret = ret.substr(0, ret.size() - 1);
	}
	int first = 0;
	while (first < ret.size() && ret[first] == '0') {
		first++;
	} 
	if (first < ret.size()) {
		ret = ret.substr(first, ret.size() - first);
	}
	bool az = true;
	for (int i = 0; i < ret.size(); i++) {
		if (ret[i] != '0' && ret[i] != '.') {
			az = false;
		}
	}
	if (az) {
		ret = "0";
	}
	return ret;
}

string process(const string& input, const vector<rule>& rules)
{
	string ret = input;
	vector<bool> ihash(ret.size(), false);
	for (int i = 0; i < rules.size(); i++) {
		int p = -1; 
		while(true) {
			p = ret.find(rules[i].first, p + 1);
			if (p == string::npos) {
				break;
			}
			if (ihash[p] == false) {
				ihash[p] = true;
				ret[p] = rules[i].second;
			}
		}
	}
	return simplify(ret);
}

int main()
{
	int nc, nrules;
	vector<rule> rules;
	rule tmp;
	string enc;
	cin >> nc;
	while (nc--) {
		cin >> nrules;
		rules.clear();
		for (int i = 0; i < nrules; i++) {
			cin >> tmp.first >> tmp.second;
			rules.push_back(tmp);
		}
		cin >> enc;
		cout << process(enc, rules) << endl;
	}
	return 0;
}