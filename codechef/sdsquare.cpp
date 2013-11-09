/**
 * Problem: http://www.codechef.com/NOV13/problems/SDSQUARE
 * Category: Simple coding
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int64_t> sdsquares;

inline bool check(int64_t n)
{
    int d;
    while(n) {
        d = n % 10;
        if(d != 0 && d != 1 && d != 4 && d != 9)
            return false;
        n /= 10;
    }
    return true;
}

void preprocess() 
{
    for(int64_t i = 1; i <= 100000; i++) {
        int d = i % 10;
        if(d == 4 || d == 5 || d == 6)
            continue;
        if(check(i*i) == true)
            sdsquares.push_back(i*i);
    }
}

int main()
{
    int64_t nc, a, b;
    preprocess();

    cin >> nc;
    while(nc--) {
        cin >> a >> b;
        int ans = 0;
        for(int i = 0; i < sdsquares.size(); i++) {
            if(sdsquares[i] >= a && sdsquares[i] <= b) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}