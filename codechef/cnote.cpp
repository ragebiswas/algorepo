#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nc, x, y, k, n;
    cin >> nc;
    while (nc--) {
        cin >> x >> y >> k >> n;
        vector<int> p(n, 0), c(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> p[i] >> c[i];
        }
        int r = x - y;
        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (p[i] >= r && c[i] <= k) {
                ans = true;
                break;
            }
        }
        cout << ( ans ? "LuckyChef\n" : "UnluckyChef\n" );
    }

    return 0;
}

