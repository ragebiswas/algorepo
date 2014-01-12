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


class LeastMajorityMultiple {
public:
	int gcd(int a, int b)
	{
	    for (;;)
	    {
	        if (a == 0) return b;
	        b %= a;
	        if (b == 0) return a;
	        a %= b;
	    }
	}

	int lcm(int a, int b)
	{
	    int temp = gcd(a, b);	
	    return temp ? (a / temp * b) : 0;
	}
	int getlcm(int a, int b, int c) {
		return lcm(lcm(a,b),c);
	}
	int leastMajorityMultiple(int a, int b, int c, int d, int e) {
		vector<int> n;
		n.push_back(a);n.push_back(b);n.push_back(c);n.push_back(d);n.push_back(e);
		sort(n.begin(), n.end());
		vector<int> res;
		for(int i=0; i<n.size(); i++)
			for(int j=0;j<n.size(); j++)
				for(int k=0;k<n.size(); k++) {
					if(i==j || i==k || j==k) continue;
						res.push_back(getlcm(n[i],n[j],n[k]));
				
				}
		sort(res.begin(), res.end());
		return res[0];
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, int p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	LeastMajorityMultiple *obj;
	int answer;
	obj = new LeastMajorityMultiple();
	clock_t startTime = clock();
	answer = obj->leastMajorityMultiple(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	int p2;
	int p3;
	int p4;
	int p5;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 2;
	p2 = 3;
	p3 = 4;
	p4 = 5;
	p5 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 30;
	p1 = 42;
	p2 = 70;
	p3 = 35;
	p4 = 90;
	p5 = 210;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 30;
	p1 = 45;
	p2 = 23;
	p3 = 26;
	p4 = 56;
	p5 = 1170;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 3;
	p1 = 14;
	p2 = 15;
	p3 = 92;
	p4 = 65;
	p5 = 195;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
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
