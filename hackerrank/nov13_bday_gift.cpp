/**
 * 20/20 Hack November: B'day Gift (https://www.hackerrank.com/contests/nov13/challenges/bday-gift)
 * Category: Simple coding/math
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    int n, s = 0, t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        s += t;
    }
    double ans = s*0.5;
    cout << setiosflags(ios::fixed) << setprecision(1) << ans << endl;        
    return 0;
}
