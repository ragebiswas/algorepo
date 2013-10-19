/**
 * 20/20 Hack October: Angry Children (https://www.hackerrank.com/contests/oct13/challenges/angry-children)
 * Category: Simple coding/math
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int ldiff = arr[n - 1];
    for(int j = 0; j < n - 1 - k; j++) {
        if(arr[j + k - 1] - arr[j] < ldiff) {
        ldiff = arr[j + k - 1] - arr[j];
        }
    }
    cout << ldiff << endl;
    return 0;
}
