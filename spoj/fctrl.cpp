/**
 * Problem: http://www.spoj.com/problems/FCTRL/
 * Category: Math (counting)
 */

#include <iostream>
using namespace std;

int main()
{
    int nc, n, cnt, t;
    cin >> nc;
    while (nc--) {
        cin >> n;
        cnt = n/5;
        t = cnt;
        while (t != 0) {
            t /= 5;
            cnt += t;
        }
        cout << cnt << endl;        
    }
    return 0;
}
