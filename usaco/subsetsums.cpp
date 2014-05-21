/*
ID: rajorsh2
PROG: subset
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	ifstream cin("subset.in");
	ofstream cout("subset.out");

    int n;
    cin >> n;
    int s = n * (n + 1) / 2;
    if (s % 2 == 1) {
        cout << 0 << endl;
    }
    else {
        s /= 2;
        vector<int> _v(s + 1, 0);
        vector<vector<int> > dp(n + 1, _v);
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= s; j++) {
                int rhs;
                if (j - i < 0) {
                    rhs = 0;
                }
                else {
                    rhs = dp[i - 1][j - i];
                }
                dp[i][j] = dp[i - 1][j] + rhs;
            }
        }
        cout << dp[n][s] << endl;
    }
    return 0;
}