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


class RestaurantManager {
public:
	int allocateTables(vector <int> tables, vector <int> groupSizes, vector <int> arrivals, vector <int> departures) {
		vector<bool> occ(200, false);
		vector<int> tableof(200, -1);
		
		int td = 0;
		for(int i=0; i<=200; i++) {
			// check departures
			for(int j=0; j<departures.size(); j++) {
				if(departures[j] == i) {
					// group j is leaving, if it was here
					if(tableof[j] != -1) {
						cout<<"Freeing table: "<<tableof[j]<<endl;
						occ[tableof[j]] = false;
						tableof[j] = -1;
					}
				}
			}
			
			// check arrivals 
			for(int k=0; k<arrivals.size(); k++) {
				if(arrivals[k] == i) {
					// group k arrived find smallest table
					int minsize = 21, seltable = -1;
					for (int t=0; t<tables.size(); t++) {
						if(tables[t] < minsize && occ[t] == false && tables[t] >= groupSizes[k]) {
							seltable = t;
							minsize = tables[t];
						}
					}
					
					// did we find?
					if(seltable == -1) {
						// nope!
						td+= groupSizes[k];
						cout<<"Turned down group:"<<k<<endl;
					}
					else {
						// yep!
						occ[seltable] = true;
						tableof[k] = seltable;
						cout<<"Selected table: "<<seltable<<" for group: "<<k<<endl;
					}
				}
			}
		}
		return td;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	RestaurantManager *obj;
	int answer;
	obj = new RestaurantManager();
	clock_t startTime = clock();
	answer = obj->allocateTables(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	{
	// ----- test 0 -----
	int t0[] = {4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,8,4,2,2,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,10,12,16,18,26};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10,20,18,26,36,28};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 14;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,8,4,2,2,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,10,12,16,18,26};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10,20,18,26,36,28};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 8;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {4,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,8,4,2,2,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,10,12,16,18,26};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10,20,18,26,36,28};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {10,8,11,16};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {14,1,15,1,19,15,9,15,20,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {4,5,7,18,21,25,29,31,46,49};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {8,37,11,36,36,46,40,42,47,50};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 69;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {18,15,2,6};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {7,9,16,3,10,3,2,10,16,16};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {10,15,19,20,21,22,27,35,37,43};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {13,24,22,32,32,32,35,48,41,44};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 10;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {13,9,6,1,9,8,6,2,8,20};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {20,10,11,10,1,5,16,2,9,17};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {12,14,64,78,100,121,151,155,162,164};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {19,26,159,96,155,134,169,199,169,174};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 17;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
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
