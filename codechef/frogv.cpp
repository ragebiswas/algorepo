/* Codechef July 2014: Chef and Frogs
 * Sorting 
 */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k, p, f1, f2;
    cin >> n >> k >> p;

    vector<int> pos(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    vector<int> arr = pos;
    sort(arr.begin(), arr.end());
    map<int, int> bucket;
    bucket[arr[0]] = 1;

    for(int i = 1; i < arr.size(); i++) {
        if (arr[i] - arr[i - 1] > k) {
            bucket[arr[i]] = bucket[arr[i - 1]] + 1;
        }
        else {
            bucket[arr[i]] = bucket[arr[i - 1]];
        }
    }

    for (int i = 0; i < p; i++) {
        cin >> f1 >> f2;
        if (bucket[pos[f1 - 1]] == bucket[pos[f2 - 1]]) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}