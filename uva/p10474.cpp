#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n, q, tmp, cn = 1;
	while (1) {
		cin >> n >> q;
		if (n == 0 && q == 0) {
			break;
		}
		cout << "CASE# " << cn << ":\n"; 
		vector<int> marbles(n);
		map<int, int> pos;
		for (int i = 0; i < n; i++) {
			cin >> marbles[i];
		}
		sort(marbles.begin(), marbles.end());
		for(int i = 0; i < marbles.size(); i++) {
			if (pos.find(marbles[i]) == pos.end()) {
				pos[marbles[i]] = i + 1;				
			}
		}
		for (int i = 0; i < q; i++) {
			cin >> tmp;
			if (pos.find(tmp) == pos.end()) {
				cout << tmp << " not found\n";
			}
			else {
				cout << tmp << " found at " << pos[tmp] << endl;
			}
		}
		cn++;
	}
	return 0;
}