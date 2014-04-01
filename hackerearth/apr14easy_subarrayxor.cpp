/*
 * Problem: http://www.hackerearth.com/april-easy-challenge-14/algorithm/subarray-xor-1/
 * Category: easy math
 * Score: 90/100
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ncases;
    ios_base::sync_with_stdio(false);
    cin >> ncases;
    while(ncases--) {
    	int n, q;
    	cin >> n;
    	vector<int> arr(n, 0);
    	for(int i = 0; i < n; i++)
    		cin >> arr[i];
    	vector<int> prefixes(n, 0), suffixes(n, 0);
    	prefixes[0] = arr[0];
    	for(int i = 0; i < n; i++) {
    		prefixes[i] = prefixes[i-1] ^ arr[i];
    	}
    	suffixes[n-1] = arr[n-1];
    	for(int i = n-2; i >=0; i--) {
    		suffixes[i] = arr[i] ^ suffixes[i+1];
    	}
    	int tot = prefixes[n-1];
    	
    	cin >> q;
    	for(int i = 0; i < q; i++) {
    		int a, b;
    		cin >> a >> b;
    		if(a == 0) {
    			cout << prefixes[b] << endl;
    		}
    		else if(b == n-1) {
    			cout << suffixes[a] << endl;
    		}
    		else {
    			cout << (tot ^ prefixes[a-1] ^ suffixes[b+1]) << endl;
    		}
    	}
    }
    return 0;
}
