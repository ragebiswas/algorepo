#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	int nlines;
	string line, country, woman, tmp;
	map<string, vector<string> > cmap;
	cin >> nlines;
	cin.ignore(100, '\n');
	while (nlines--) {
		getline(cin, line);
		istringstream iss(line);
		iss >> country;
		woman = "";
		while (iss >> tmp) {
			woman += tmp;
		}
		if (cmap.find(country) == cmap.end()) {
			vector<string> women;
			cmap[country] = women;
		}
		vector<string>& women = cmap[country];
		bool found = false;
		for (int i = 0; i < women.size(); i++) {
			if (women[i] == woman) {
				found = true;
				break;
			}
		}

		if (!found) {
			women.push_back(woman);
		}
	}

	for(map<string, vector<string> >::iterator it = cmap.begin(); it != cmap.end(); ++it)
	{
		cout << it->first << ' ' << (it->second).size() << endl;
	}

	return 0;
}