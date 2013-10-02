/**
 * SPOJ: http://www.spoj.com/problems/FASHION/
 * Category: Simple coding
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int nc, n, tot;
    cin >> nc;
    while(nc--) {
        cin >> n;
        vector<int> m(n, 0), f(n, 0);
        for(int i = 0; i < n; i++) 
            cin >> m[i];
        for(int i = 0; i < n; i++) 
            cin >> f[i];
        sort(m.begin(), m.end());
        sort(f.begin(), f.end());
        tot = 0;
        for(int i = n - 1; i >= 0; i--) {
            tot += m[i] * f[i];
        }
        cout << tot << endl;
    }
    return 0;
}
