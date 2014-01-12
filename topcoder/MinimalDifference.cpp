#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class MinimalDifference {
public:
	int dsum(int n) {
		int sum = 0;
		while(n) {
			sum += n%10;
			n/= 10;
		}
		return sum;
	}
	int findNumber(int A, int B, int C) {
		int mindiff = 100;
		int minnum = max(A, B);
		if(B<A) swap(A,B);
		for(int i=A; i<=B; i++) {
			if(abs(dsum(i)-dsum(C)) < mindiff) {
				mindiff = abs(dsum(i)-dsum(C));
				minnum = i;
			}
		}
		return minnum;
	}
};



//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
