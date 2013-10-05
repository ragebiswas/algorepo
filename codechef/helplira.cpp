/**
 * Problem: http://www.codechef.com/OCT13/problems/HELPLIRA
 * Category: Simple coding
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int nc, idx = 1;
    int maxa = 0, mina = 10000000;
    int mini = 0, maxi = 0;
    cin >> nc;
    while (nc--) {
        int x1, x2, x3, y1, y2, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int ar2 = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
        ar2 = abs(ar2);
        if (ar2 <= mina) {
            mina = ar2;
            mini = idx;
        }
        if (ar2 >= maxa) {
            maxa = ar2;
            maxi = idx;
        }
        idx++;            
    }
    cout << mini << " " << maxi << endl;        
    return 0;
}
