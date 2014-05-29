// Where's Waldorf (Level 1)
// Array/string manipulation
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool search(vector<string>& vs, int r, int c, string query)
{
	for (int x = -1; x <= 1; x++) {
		for(int y = -1; y <= 1; y++) {
			int xv = r, yv = c;
			if (x == 0 && y == 0) {
				continue;
			}
			bool found = true;
			int o;
			for (o = 0; o < query.size(); o++) {
				if (xv < 0 || xv >= vs.size() || yv < 0 || yv >= vs[0].size()) {
					found = false;
					break;
				}
				if (toupper(vs[xv][yv]) != toupper(query[o])) {
					found = false;
					break;
				}
				xv += x;
				yv += y;				
			}

			if (found && o == query.size()) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int nc;
	vector<string> arr;
	cin >> nc;
	for (int cn = 0; cn < nc; cn++) {
		int R, C, Q;
		string t;
		cin >> R >> C;
		arr.clear();
		for(int i = 0; i < R; i++) {			
			cin >> t;
			arr.push_back(t);
		}
		cin >> Q;
		for(int q = 0; q < Q; q++) {
			cin >> t;
			bool found = false;
			for(int i = 0; i < R; i++) {
				if (found) {
					break;
				}
				for(int j = 0; j < C; j++) {
					if (found) {
						break;
					}
					if (search(arr, i, j, t)) {
						cout << i + 1 << " " << j + 1 << endl; 
						found = true;
					}

				}
			}
		}
		if (cn != nc - 1) {
			cout << endl;
		}
	}
}