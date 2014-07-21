#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string re_sort(string ans)
{
    string cons = "", vow = "", ret = "";
    for (int i = 0; i < ans.size(); i++) {
        if (i % 2) {
            cons += ans[i];
        }
        else {
            vow += ans[i];
        }
    }
    sort(cons.begin(), cons.end());
    sort(vow.begin(), vow.end());
    int ci = 0, vi = 0;
    for (int i = 0; i < ans.size(); i++) {
        if (i % 2) {
            ret += cons[ci++];
        }
        else {
            ret += vow[vi++];
        }
    }  
    return ret;  
}

int main()
{
    vector<int> val('Z' + 1, 0);
    val['A'] = 1;
    string vowels = "AUEOI";
    string consonants = "JSBKTCLDMVNWFXGPYHQZR";

    // char to int map
    for (int i = 'A' + 1; i <= 'Z'; i++) {
        val[i] = (val[i - 1] + 1);
        if (val[i] == 10) {
            val[i] = 1;
         }
    }

    int nc, len;
    cin >> nc;
    for (int cn = 1; cn <= nc; cn++) {
        cin >> len;
        vector<int> vusage('Z' + 1, 0), cusage('Z' + 1, 0);
        bool v = true;
        int vi = 0, ci = 0;
        string ans = "";
        for (int i = 0; i < len; i++) {
            if (v) {
                if (vusage[vi] >= 21) {
                    vi++;
                }
                vusage[vi]++;
                ans += vowels[vi];
            }
            else {
                if (cusage[ci] >= 5) {
                    ci++;
                }
                cusage[ci]++;
                ans += consonants[ci];
            }
            v = !v;
        }
        ans = re_sort(ans);
        cout << "Case " << cn << ": " << ans << endl;
    }

    return 0;
}
