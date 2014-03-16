/**
 * Problem: http://www.codechef.com/MARCH14/problems/PROSUM
 * Category: Basic counting
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long ncases, n, t;
    cin >> ncases;
    while (ncases--) {
        cin >> n;
        long long nz = 0, n1 = 0, n2 = 0, gt1 = 0;
        for (long long i = 0; i < n; i++) {
            cin >> t;
            switch (t) {
            case 0:
                nz++;
                break;
            case 1:
                n1++;
                break;
            case 2:
                n2++;
                break;
            default:
                break;
            }
        }
        long long tot = n * (n - 1) / 2;
        //cout << "Total:" << tot << endl;
        tot -= (nz * n - nz * (nz + 1) / 2);
        //cout << "Removed zeros:" << tot << endl;
        gt1 = n - nz;
        tot -= (n1 * gt1 - n1 * (n1 + 1) / 2);
        //cout << "Removed ones:" << tot << endl;
        tot -= n2 * (n2 - 1) / 2;
        cout << tot << endl;
    }

    return 0;
}