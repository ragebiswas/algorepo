/**
 * Problem: https://www.hackerrank.com/contests/mar14/challenges/sherlock-and-squares
 * Category: Simple coding
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int ncases; 
  cin >> ncases;
  
  while(ncases--) {
  	int a, b, c = 0;
    cin >> a >> b;
    for(int k = 1; k < 32000; k++) {
      int t = k*k;
      if(t >= a && t <= b)
        c++;
    }
    cout << c << endl;
  }
  
  return 0;
}
