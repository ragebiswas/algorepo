#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;


int main() 
{
	int ncases=1;
	cin>>ncases;
	string s;
	getline(cin, s);

	for(int i=0; i<ncases; i++) {
		getline(cin, s);
		vector<int> v(200, 0);
		for(int j=0; j<s.size(); j++) {
            char x = s[j];
            if((x>='a' && x<='z') || (x>='A' && x<='Z'))
                v[x]++;
		}
		
		int c = 0;
		for(int j=0; j<200; j++) {
			c += v[j]/2;
			if(v[j]%2 == 1) 
				c++;
		}
		cout<<c<<endl;
	}

	return 0;
}