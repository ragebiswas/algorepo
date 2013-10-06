/**
 * Problem: http://www.spoj.com/problems/CANDY/
 * Category: Simple coding
 */

#include <iostream>
using namespace std;

int main()
{
    int n, arr[10001], tot, avg, ans;
    while(1) {
        cin >> n;
        if(n == -1) 
            break;
        tot = 0;
        ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            tot += arr[i];
        }
        if(tot % n != 0) {
            cout << -1 << endl;
            continue;
        }
        avg = tot/n;
        for(int i = 0; i < n; i++) {
            if(arr[i] > avg) 
                ans += (arr[i] - avg);
        }
        cout << ans << endl;
    }
    return 0;
}
