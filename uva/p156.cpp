#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	string line, tmp;
	vector<string> words;
	map<string, int> wmap;
	while (getline(cin, line)) {
		if (line == "#") {
			break;
		}
		istringstream iss(line);
		while (iss >> tmp) {
			words.push_back(tmp);
			transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
			sort(tmp.begin(), tmp.end());
			if (wmap.find(tmp) == wmap.end()) {
				wmap[tmp] = 0;
			}
			wmap[tmp]++;
		}
	}
	vector<string> ans;
	for (int i = 0; i < words.size(); i++) {
		tmp = words[i];
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		sort(tmp.begin(), tmp.end());
		if (wmap[tmp] == 1) {
			ans.push_back(words[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}