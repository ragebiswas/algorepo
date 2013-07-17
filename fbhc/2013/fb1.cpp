#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

class cpair {
public:
    bool operator()(pair<int, int>& p1, pair<int, int>& p2)
    {
		if(p1.second > p2.second)
			return false;
		else
			return true;
    }
};

int main() 
{
	int ncases = 0, cn = 1;
	cin>>ncases;
	string str;
	getline(cin,str);

	while(ncases--) {
		getline(cin, str);

		vector<int> m(26, 0);
		priority_queue< pair<int,int>, vector< pair<int,int> >, cpair > pqueue;

		for(int i=0; i<str.size(); i++) {
			char c = toupper(str[i]);
			if(isalpha(c)) m[c-'A']++;
		}

		for(int i=0; i<26; i++) {
			if(m[i] > 0) pqueue.push(make_pair(i, m[i]));
		}
		
		int s = 0, c = 26;
		while(pqueue.size()) {
			pair<int, int> p = pqueue.top();
			pqueue.pop();
			s += c*p.second;
			c--;
		}

		cout<<"Case #"<<cn++<<": "<<s<<endl;
	}

	return 0;
}