// Decode the tape (Level 1: String)
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string line;
	while (getline(cin, line)) {
		if (line.find('o') != string::npos) {
			int j = 0, c = 0;
			for (int i = line.size() - 1; i >= 0; i--) {
				if (line[i] == 'o') {
					c += (1 << j);
				}
				if (line[i] == 'o' || line[i] == ' ') {
					j++;
				}
			}
			cout << (char)c;
		}
	}
	return 0;
}