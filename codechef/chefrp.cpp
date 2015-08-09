#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int nc; 
    cin >> nc;
    while (nc--) {
        int n; 
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long int ans = 0;
        for (int i = arr.size() - 1; i > 0; i--) {
            if (arr[i] < 2) {
                ans = -1;
                break;
            }
            else {
                ans += arr[i];
            }
        }
        if (arr[0] < 2) {
            ans = -1;
        }
        else {
            ans += 2;
        }
        cout << ans << endl;
    }
    return 0;
}
