/*
 * Problem: http://www.hackerearth.com/april-easy-challenge-14/algorithm/little-deepu-and-his-girlfriend-2/
 * Category: easy logic/games/dp
 * Score: 50/100
 */
#include <iostream>
#include <vector>
using namespace std;

bool iswinning(int x, vector<int>& w)
{
	vector<bool> ret(x + 1, false);
	for(int i = 1; i <= x; i++) {
		for(int j = 0; j < w.size(); j++) {
			int J = w[j];
			if((i - J >= 0) && ret[i - J] == false) 
				ret[i] = true;
		}		
	}
	return ret[x];
}

int main()
{
	ios_base::sync_with_stdio(false);
    int ncases;
    cin >> ncases;
    
    while(ncases--) {
    	int m, n;
    	cin >> m >> n;
    	vector<int> w(n, 0);
    	for(int i = 0; i < n; i++)
    		cin >> w[i];
 		if(iswinning(m, w))
 			cout << "Little Deepu\n";
 		else
 			cout << "Kate\n";    	
    }
    
    return 0;
}
