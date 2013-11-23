/**
 * 20/20 Hack November: Utopian Tree (https://www.hackerrank.com/contests/nov13/challenges/utopian-tree)
 * Category: Simple coding
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int nc, h, c;
    cin >> nc;
    while(nc--) {
        h = 1;
        cin >> c;
        for(int i = 1; i <= c; i++) {
            if(i % 2)    
                h *= 2;
            else
                h++;            
        }
        cout << h << endl;
    }    
    return 0;
}
