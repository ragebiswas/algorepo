// Andy's First Dictionary (Level 1: String)
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> process(string word)
{
	vector<string> ret;
	string tmp = "";
	for (int i = 0; i < word.size(); i++) {
		if (!isalpha(word[i])) {
			if (tmp.size() != 0) {
				ret.push_back(tmp);
			}
			tmp = "";
		}
		else {
			tmp += ::tolower(word[i]);
		}
	}	

	if (tmp.size() != 0) {
		ret.push_back(tmp);
	}
	return ret;
}

int main()
{
	string word;
	map<string, bool> wmap;
	while (cin >> word) {
		vector<string> toks = process(word);
		for (int i = 0; i < toks.size(); i++) {
			wmap[toks[i]] = true;
		}	
	}	
	for (map<string, bool>::iterator it = wmap.begin(); it != wmap.end(); ++it) {
		cout << it->first << endl;
	}
	return 0;
}