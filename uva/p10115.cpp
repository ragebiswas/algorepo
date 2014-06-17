// Automatic Editing 
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

string process(string input, const vector<string>& fs, const vector<string>& rs)
{
	string ret = input;
	for (int i = 0; i < fs.size(); i++) {
		string findstr = fs[i];
		while (1) {
			int pos = ret.find(fs[i]);
			if (pos == string::npos) {
				break;
			}
			ret.replace(pos, findstr.size(), rs[i]);
		}
	}
	return ret;
}

int main()
{
	int nrules;
	string tmp;
	while (1) {
		cin >> nrules;
		if (nrules == 0) {
			break;
		}
		cin.ignore(500, '\n');
		vector<string> fs, rs;
		for (int i = 0; i < nrules; i++) {
			getline(cin, tmp);
			fs.push_back(tmp);
			getline(cin, tmp);
			rs.push_back(tmp);
		}
		getline(cin, tmp);
		cout << process(tmp, fs, rs) << endl;
	}
	return 0;
}