// Problem: http://www.codechef.com/MAY14/problems/COMPILER
// Category: Easy logic
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solve(string& s)
{
    stack<char> st;
    int vmax = -1;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (s[i] == '<') {
            st.push('<');
        }
        else {
            if (!st.empty() && st.top() == '<') {
                st.pop();
                if (st.empty()) {
                    vmax = i;
                }
            }
            else {
                return vmax + 1;
            }
        }
    }

    return vmax + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    int ncases;
    string s;
    cin >> ncases;

    while (ncases--) {
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}