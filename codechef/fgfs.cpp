/**
 * Problem: http://www.codechef.com/JAN14/problems/FGFS
 * Category: Greedy (Interval scheduling)
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

typedef pair<int, int> entry;

struct sort_pred {
    bool operator()(const entry& left, const entry& right) {
        return left.second < right.second;
    }
};

int solve(vector<entry>& entries) {
    int ret = 0;
    vector<entry> selected;
    for (int i = 0; i < entries.size(); i++) {
        entry cur = entries[i];
        bool valid = true;
        for (int j = 0; j < selected.size(); j++) {
            entry s = selected[j];
            if (!(cur.second <= s.first || cur.first >= s.second)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            selected.push_back(cur);
            ret++;
        }
    }
    return ret;
}

map<int, vector<entry> > m;

int main()
{
    ios::sync_with_stdio(false);
    int ncases;
    cin >> ncases;

    while (ncases--) {
        int n, k, r;
        cin >> n >> k; 
        m.clear();

        // Input!
        for (int i = 0; i < n; i++) {
            entry e;
            cin >> e.first >> e.second >> r;
            if (m.find(r - 1) == m.end()) {
                vector<entry> t;
                m[r - 1] = t;
            }
            m[r - 1].push_back(e);
        }

        int ans = 0;
        // Sort entries for each room
        for (map<int, vector<entry> >::iterator i = m.begin(); i != m.end(); i++) {
            sort(i->second.begin(), i->second.end(), sort_pred());
            ans += solve(i->second);
        }
        
        cout << ans << endl;
    }

    return 0;
}
