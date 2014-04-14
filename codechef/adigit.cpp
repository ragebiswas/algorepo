// Codechef April 2014 Long
// Easy math / logic
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m;

    vector<int> arr(n, 0);
    vector<int> _t(10, 0);
    vector<vector<int> > counts(n, _t);
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        arr[i] = s[i] - '0';
        if (i > 0) {
            counts[i] = counts[i - 1];
        }
        counts[i][arr[i]]++;
    }

    for (int i = 0; i < m; i++) {
        cin >> q;
        q--;
        if (q == 0) {
            cout << 0 << endl;
            continue;
        }
        int b1 = 0, b2 = 0, x = arr[q];
        vector<int> c = counts[q - 1];
        for (int j = 0; j < 10; j++) {
            if (x > j) {
                b1 += (x - j) * c[j];
            }
            else {
                b2 += (x - j) * c[j];
            }
        }
        cout << b1 - b2 << endl;
    }

    return 0;

}
