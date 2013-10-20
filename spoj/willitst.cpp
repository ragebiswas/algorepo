/**
 * Problem: http://www.spoj.com/problems/WILLITST/
 * Category: Simple coding
 */
#include <iostream>
#include <map>

typedef unsigned long long int64;
using namespace std;

int main()
{
    int64 n;
    cin >> n;
    map<int64, int> m;
    
    while(n > 1) {
        if (m.find(n) != m.end()) {
            cout << "NIE\n";
            return 0;
        }
        m[n] = 1;
        if (n % 2 == 0) 
            n /= 2;
        else
            n = 3*n + 3;
    }
    cout << "TAK\n";
    return 0;
}
    