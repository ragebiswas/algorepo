/**
 * Problem: http://www.spoj.com/problems/COINS/
 * Category: Simple recursion
 */
#include <iostream>
#include <map>
using namespace std;

map<int64_t, int64_t> memo;

int64_t getval(int64_t n) 
{
    if (n <= 1)
        return n;
        
    int64_t by2, by3, by4;
    if(memo.find(n/2) != memo.end()) 
        by2 = memo[n/2];
    else 
        by2 = getval(n/2);
    if(memo.find(n/3) != memo.end()) 
        by3 = memo[n/3];
    else 
        by3 = getval(n/3);
    if(memo.find(n/4) != memo.end()) 
        by4 = memo[n/4];
    else 
        by4 = getval(n/4);
        
    int64_t val = max(n, by2 + by3 + by4);
    memo[n] = val;
    return val;
}

int main()
{
    int64_t n;
    while(cin >> n) {
        cout << getval(n) << endl;
    }
    return 0;
}
