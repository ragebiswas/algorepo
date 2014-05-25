// Triangle wave
// Easy coding: Level 0
#include <iostream>
using namespace std;

int main()
{
	int ncases;
	cin >> ncases;
	for(int c = 0; c < ncases; c++) {
		int amp, freq;
		cin >> amp >> freq;
		for(int i = 0; i < freq; i++) {
			for(int j = 1; j <= amp; j++) {
				for(int k = 0; k < j; k++) {
					cout << j;
				}
				cout << endl;
			}
			for(int j = amp - 1; j >= 1; j--) {
				for(int k = 0; k < j; k++) {
					cout << j;
				}
				cout << endl;
			}
			if (i != freq - 1) {
				cout << endl;
			}
		}
		if (c != ncases - 1) {
			cout << endl;
		}
	}
	return 0;
}