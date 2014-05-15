// Problem: http://www.codechef.com/MAY14/problems/RRSTONE
// Category: Easy logic
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;


void process(vector<int64_t>& vi) 
{
	int64_t maxElem = *max_element(vi.begin(), vi.end());
	for(int i = 0; i < vi.size(); i++) {
		vi[i] = maxElem - vi[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n, k;

	cin >> n >> k;
	vector<int64_t> arr(n, 0);
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (k != 0) {
		k = ((k % 2) ? 1 : 2);
	}

	for(int i = 0; i < k; i++) {e
		process(arr);
	}

	for(int i = 0; i < n; i++) {
		cout << arr[i];
		cout << ((i == n - 1) ? '\n' : ' ');
	}

	return 0;
}