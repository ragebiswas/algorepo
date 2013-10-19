/**
 * 20/20 Hack October: Chocolate Feast (https://www.hackerrank.com/contests/oct13/challenges/chocolate-feast)
 * Category: Simple coding
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, c, m, nc;
    cin >> nc;
    while (nc--) {
        cin >> n >> c >> m;
        int ans = 0, wrappers = 0;
        ans += n/c;
        wrappers += n/c;
        while(wrappers >= m) {
            int tmp = wrappers/m;
            wrappers = tmp + (wrappers % m);
            ans += tmp;
        }
        cout << ans << endl;
    }
    return 0;
}
