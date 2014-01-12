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

struct compare  
{  
  bool operator()(const int& l, const int& r)  
  {  
      return l > r;  
  }  
}; 

class Stick {
public:
	int pieces(int x) {
		list<int> pq;
		pq.push_front(64);
		
		
		while(true)
		{
			cout<<"here"<<endl;
			int ls = accumulate(pq.begin(), pq.end(), 0);
			if(ls == x) break;
			
			int front = pq.front(); pq.pop_front();
			int f2 = front/2;
			
			pq.push_front(f2);
			//pq.push_front(f2);
			
			list<int>::const_iterator itr;
            for(itr=pq.begin(); itr!=pq.end(); itr++){ 
                    cout<<(*itr)<<","; 
                }
                cout<<"\n";
			
			ls = accumulate(pq.begin(), pq.end(), 0);
			cout<<"ls="<<ls<<endl;
			if(ls < x) {
							cout<<"nothere"<<endl;
				//pq.pop_front();
				pq.push_front(f2);
			}		
			
		}
		
		return pq.size();
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	Stick *obj;
	int answer;
	obj = new Stick();
	clock_t startTime = clock();
	answer = obj->pieces(p0);
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
	p0 = 32;
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 48;
	p1 = 2;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 23;
	p1 = 4;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
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
