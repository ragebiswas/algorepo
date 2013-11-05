/**
 * Problem: http://www.codechef.com/NOV13/problems/JOHNY/
 * Category: Simple coding
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nc, arr[101];
    cin >> nc;
    while(nc--) {
        int n, k;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(arr[i] < arr[k-1]) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}