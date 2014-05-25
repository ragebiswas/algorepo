// Linear Cellular Automata (level 0)
#include <iostream>
#include <vector>
using namespace std;

char tr(int n) {
	switch(n) {
		case 0: return ' ';
		case 1: return '.';
		case 2: return 'x';
		case 3: return 'W';
	}
	return 0;
}

void print(vector<int>& arr) {
	for(int i = 1; i <= 40; i++) {
		cout << tr(arr[i]);
	}
	cout << endl;
}

int main()
{
	int ncases, dna[10];	
	cin >> ncases;

	for(int c = 0; c < ncases; c++) {
		for(int i = 0; i < 10; i++) {
			cin >> dna[i];
		}
		vector<int> prev(42, 0) , cur(42, 0);
		prev[20] = 1;
		print(prev);
		for(int i = 2; i <= 50; i++) {
			for(int j = 1; j <= 40; j++) {
				int sum = prev[j - 1] + prev[j] + prev[j + 1];
				cur[j] = dna[sum];
			}
			print(cur);
			prev = cur;
		}
		if (c != ncases - 1) {
			cout << endl;	
		} 
	}

	return 0;
}