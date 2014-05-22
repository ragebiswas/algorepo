// Marvelous mazes
// Trivial coding
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string line;

	while (getline(cin, line)) {
		int r = 0;
		for(int i = 0; i < line.size(); i++) {
			char c = line[i];
			if(isdigit(c)) {
				r += c - '0';
			}
			else if(c == '!') {
				cout << '\n';
				r = 0;
			}
			else {
				for(int j = 0; j < r; j++) {
					cout << (c == 'b' ? ' ' : c);
				}
				r = 0;
			}
		}
		cout << '\n';
	}
	return 0;
}