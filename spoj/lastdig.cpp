/**
 * Problem: http://www.spoj.com/problems/LASTDIG/
 * Category: Simple math
 */
#include <iostream>
using namespace std;

int main()
{
    long long int nc, b, e, a, i;
    cin >> nc;
    while(nc--) {
        cin >> b >> e;
        if(e == 0) {
            cout << 1 << endl;
            continue;
        }
        // Main observation: the pattern of digits repeat after
        // 4 times
        e %= 4;
        if(e == 0) 
            e = 4;
        a = 1;
        for(i = 0; i < e; i++)
            a *= b;
        cout << a%10 << endl;
    }
    return 0;
}
