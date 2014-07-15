#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int nc, n;
	cin >> nc;
	while (nc--) {
		cin >> n;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int nswaps = 0;
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for (int i = 0; i < n - 1; i++) {
				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
					sorted = false;
					nswaps++;
				}
			}
		}
		cout << "Optimal train swapping takes " << nswaps << " swaps.\n";
	}
	return 0;
}