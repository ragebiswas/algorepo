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


class TheLargestLuckyNumber {
public:
	int p10(int n) {
		int r=1;
		while(n--) r*=10;
		return r;
	}
	int find(int inp) {
		int lucky[2000];
				
		int j = 0, k = 0;
		
		lucky[0] = 4;
		lucky[1] = 7;
		k = 2;
		int p = 2;
		
		while(p<1000)
		{
			int tmp = p;
			for(int j0=j;j0<=p;j0++)
			{
				int n = lucky[j0];
				double dg = floor(log10(n))+1;
				int dgn = (int)dg;
				int w = p10(dgn)*4 + n;
				
				if(p > 1000) break;
				
				lucky[p++] = w;
				w = p10(dgn)*7 + n;
				lucky[p++] = w;
				
			}
			j = p;
		}
		
		vector<int> l;
		for(int i=0;i<1000;i++) l.push_back(lucky[i]);
		sort(l.begin(), l.end());
		
		for(int i=0; i<500; i++) 
		{
			if(inp >= l[i] && inp < l[i+1])
				return l[i];
		}
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	TheLargestLuckyNumber *obj;
	int answer;
	obj = new TheLargestLuckyNumber();
	clock_t startTime = clock();
	answer = obj->find(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	
	{
	// ----- test 0 -----
	p0 = 100;
	p1 = 77;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 75;
	p1 = 74;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5;
	p1 = 4;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 474747;
	p1 = 474747;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
