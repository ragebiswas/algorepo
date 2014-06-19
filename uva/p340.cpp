// UVA: Master Mind Hints
// Easy coding
#include <iostream>
#include <vector>
using namespace std;

bool all_zeroes(const vector<int>& v) 
{
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 0) {
			return false;
		}
	}
	return true;
}

void process(vector<int> v, vector<int> g)
{
	int a = 0, b = 0;
	for(int i = 0; i < v.size(); i++) {
		if (v[i] == g[i]) {
			a++;
			v[i] = -1; 
			g[i] = -1;
		}
	}
	for(int i = 0; i < v.size(); i++) {
		for (int j = 0; j < g.size(); j++) {
			if (v[i] == g[j] && (v[i] != -1)) {
				b++;
				v[i] = -1;
				g[j] = -1;
			}
		}
	}
	cout << "    (" << a << "," << b << ")\n";
}

int main()
{
	int n, cn = 1;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cout << "Game " << cn++ << ":\n";
		vector<int> arr(n, 0), guess(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		while (1) {
			for (int i = 0; i < n; i++) {
				cin >> guess[i];
			}
			if (all_zeroes(guess)) {
				break;
			}
			else {
				process(arr, guess);
			}
		}
	}
	return 0;
}