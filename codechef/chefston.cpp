#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        uint64_t n, k, mp = 0, tp;
        cin >> n >> k;
        vector<uint64_t> times(n, 0), profits(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> times[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> profits[i];
            if (times[i] <= k) {
                tp = (k / times[i]) * profits[i];
                mp = max(tp, mp);
            }
        }
        cout << mp << endl;
    }
    return 0;
}
