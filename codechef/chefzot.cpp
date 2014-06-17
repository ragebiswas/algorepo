// Codechef June 2014: Chef and Subarray
// Easy coding
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int max_ans = 0, max_cur = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			max_ans = max(max_ans, max_cur);
			max_cur = 0;
		}
		else {
			max_cur++;
		}
	}
	max_ans = max(max_ans, max_cur);
	cout << max_ans << endl;	
	return 0;
}