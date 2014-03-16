#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = 0;
        for (int j = n - 1; j >= 0; j--) {
            ans = max(arr[j], ans + 1);
        }
        cout << ans << endl;
 
    }
 
} 