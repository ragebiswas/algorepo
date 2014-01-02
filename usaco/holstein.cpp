/*
ID: rajorsh2
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream cin("holstein.in");
    ofstream cout("holstein.out");

    int ntypes, nfeeds;

    cin >> ntypes;
    vector<int> reqs(ntypes, 0);
    for (int i = 0; i < ntypes; i++) {
        cin >> reqs[i];
    }

    cin >> nfeeds;
    vector<int> _feed(ntypes, 0);
    vector<vector<int> > feeds(nfeeds, _feed);
    for (int i = 0; i < nfeeds; i++) {
        for (int j = 0; j < ntypes; j++) {
            cin >> feeds[i][j];
        }
    }

    vector<int> best;
    for (int i = 0; i < nfeeds; i++)
        best.push_back(i);
        
    for (int i = 1; i <= (1 << nfeeds); i++) {
        vector<int> selected;
        for (int j = 0; j < nfeeds; j++) {
            if (i & (1 << j)) {
                selected.push_back(j);
            }
        }
        vector<int> totals(ntypes, 0);
        for (int j = 0; j < selected.size(); j++) {
            vector<int> feed = feeds[selected[j]];
            for (int k = 0; k < ntypes; k++) {
                totals[k] += feed[k];
            }
        }

        bool satisfies = true;
        for (int j = 0; j < ntypes; j++) {
            if (reqs[j] > totals[j])  {
                satisfies = false;
                break;
            }
        }

        if (satisfies && selected.size() < best.size()) {
            best = selected;
        }
    }

    cout << best.size() << " ";
    for (unsigned i = 0; i < best.size() - 1; i++) {
        cout << best[i] + 1 << " ";
    }
    cout << best[best.size() - 1] + 1 << endl;
    
    return 0;
}