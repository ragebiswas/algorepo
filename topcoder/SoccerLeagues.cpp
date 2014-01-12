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


class SoccerLeagues {
public:
	vector <int> points(vector <string> matches) {
		vector<int> scores(matches.size(), 0);
		for(int i=0; i<matches.size();i++) {
			for(int j=0;j<matches[0].size();j++) {
				if(matches[i][j]=='W') scores[i]+=3;
				if(matches[i][j]=='L') scores[j]+=3;
				if(matches[i][j]=='D') { scores[i]++; scores[j]++; }
			}
		}
		return scores;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	SoccerLeagues *obj;
	vector <int> answer;
	obj = new SoccerLeagues();
	clock_t startTime = clock();
	answer = obj->points(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	
	vector <string> p0;
	vector <int> p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"-WW","W-W","WW-"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {6,6,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"-DD","L-L","WD-"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {5,2,8};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"-DWWD","L-WLL","DD-WD","DDL-L","DDLL-"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {14,7,12,8,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"-LWWLWDLDWWWWWWDDWDW","D-WWLDDWDWDLWDDWLWDD","LL-DLDWDLDLDWWWLWDDW","LDD-LLLDLWLWWWWDWDWL","LWWW-DWDLWDWDWWWDWDW","DLLWD-WWLLDDDLWWDWWW","WWLWDL-LLDWWWWWDWWLW","LLLLLDW-LDLWDDLLLDWL","DWWWWDDD-DWWWWDWWWDW","WWWWLLLWL-LWWWWWLWWW","DWWWWWWWLW-WDWWWWWWW","DDDLLLDWWWL-DDWDWLDD","LWLWLDLLLDLW-DDDWWDD","LLWWLWDDLWLWL-WWWDLL","WWWWLLDDDWLWDD-WWWLW","DLDLLLWWLLLWWLW-DWLL","DLWWWLDLWWDWWDWL-WWD","LLDDLLWLLWLWLDLWW-WW","LLWLLLWWLWLWWDWWLD-W","LLWDLWDWDWLLWWDDWWL-"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {72,62,41,41,83,63,53,35,86,50,90,32,34,41,45,36,51,32,51,45};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
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
