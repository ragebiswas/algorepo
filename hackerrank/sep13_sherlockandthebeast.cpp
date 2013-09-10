/*
 * Hackerrank Sep 13
 * Problem: https://www.hackerrank.com/contests/sep13/challenges/sherlock-and-the-beast
 * Category: Easy Coding
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline bool works(int n5, int n3) 
{
    if(n5 % 3 == 0 && n3 % 5 == 0)
        return true;
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        int n5 = n;
        int n3 = 0;
        bool found = true;
        while(!works(n5, n3)) {
            n5--;
            n3++;
            if(n5 < 0) {
                found = false;
                break;
            }
        }
        if(found) {
            for(int i = 0; i < n5; i++)
                cout << '5';
            for(int i = 0; i < n3; i++)
                cout << '3';
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}
