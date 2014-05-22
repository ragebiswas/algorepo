// Volume 0: Getting Started
// Easy coding
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> arr;
	string s;
	int maxlen = 0;
	while(getline(cin, s)) {
		arr.push_back(s);
		maxlen = max(maxlen, (int)s.size());
	}

	for(int r = 0; r < maxlen; r++) {
		for(int c = arr.size() - 1; c >= 0; c--) {
			string s = arr[c];
			cout << (r < s.size() ? s[r] : ' ');
		}
		cout << endl;
	}
	return 0;
}