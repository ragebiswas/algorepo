/*
 * Problem: http://www.codechef.com/AUG13/problems/LELEMON/
 * Category: Simple Coding
 */
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int t, n, m, c;
    cin >> t;
    while(t--) {

        // input
        cin >> n >> m;

        vector<int> visited(m, 0);
        vector< list<int> > bottles(n);

        for(int i = 0; i < m; i++) {
            cin >> visited[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> c;
            vector<int> vtmp(c, 0);

            for(int k = 0; k < c; k++) {
                cin>>vtmp[k];
            }
            sort(vtmp.begin(), vtmp.end(), greater<int>());
            list<int> ltmp;

            copy(vtmp.begin(), vtmp.end(), back_inserter(ltmp));
            bottles[i] = ltmp;
        }

        // algorithm
        int total = 0;
        for(int i = 0; i < m; i++) {
            list<int>& b = bottles[visited[i]];
            if(b.empty()) {
                continue;
            }
            total += b.front();
            b.pop_front();
        }

        cout << total << endl;
    }
    return 0;
}
