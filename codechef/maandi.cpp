/**
 * Problem: http://www.codechef.com/OCT13/problems/MAANDI
 * Category: Simple math
 */
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

inline bool isoverlucky(int n)
{
    while(n) {
        if(n % 10 == 4 || n % 10 == 7)
            return true;
        n /= 10;
    }
    return false;
}


int main()
{
    int nc;
    cin >> nc;
    while(nc--) {
        int n, nol = 0;
        cin >> n;
        int lim = sqrt(n);
        for(int i = 1; i <= lim; i++) {
            if(n % i == 0) {
                if(isoverlucky(i)) nol++;
                if(isoverlucky(n/i)) nol++;
            }
        }
        cout << nol << endl;
    }

    return 0;
}
