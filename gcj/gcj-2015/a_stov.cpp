#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int nc, n;
    string s;
    cin >> nc;
    for (int c = 1; c <= nc; c++) {
        // initialize 
        cin >> n >> s;
        vector<int> shy(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            shy[i] = s[i] - '0';
        }
        // calculate!
        int ans = 0, ppl = shy[0];
        for (int i = 1; i <= n; i++) {
            if (ppl < i) {
                ans += (i - ppl);
                ppl += (i - ppl);
            }
            ppl += shy[i];
        }
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}
