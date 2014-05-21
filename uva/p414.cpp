// Volume 0: Getting Started
// Easy coding
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int solve(vector<string>& s)
{
	vector<int> spaces;
	int minspaces = 100;

	for(int i = 0; i < s.size(); i++) {
		string l = s[i];
		int nspaces = 0;
		for(int j = 0; j < l.size(); j++) {
			if(l[j] == ' ') {
				nspaces++;
			}
		}
		minspaces = min(nspaces, minspaces);
		spaces.push_back(nspaces);
	}

	int totspaces = accumulate(spaces.begin(), spaces.end(), 0);
	return totspaces - minspaces * spaces.size();
}

int main()
{
	int n;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cin.ignore (100, '\n'); 
		vector<string> arr(n);
		for(int i = 0; i < n; i++) {
			getline(cin, arr[i]);
		}
		cout << solve(arr) << endl;
	}
	return 0;
}