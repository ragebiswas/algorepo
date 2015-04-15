#include <iostream>
#include <cmath>
#include <map>
using namespace std;
typedef long long int lli;

int main()
{
    int nc;
    cin >> nc;
    while (nc--) {
        lli n;
        cin >> n;
        if (n == 1) {
            cout << n << endl;
        }
        else {
            lli root = sqrt(n);
            long long ans = 0;
            map<lli, lli> m;
            for (lli i = 2; i <= root; i++) {
                if (n % i == 0) {
                    if (m.find(i) == m.end()) {
                        ans += i;
                        m[i] = 1;
                    }
                    if (m.find(n/i) == m.end()) {
                        ans += (n / i);
                        m[n/i] = 1;
                    }
                }
            }
            cout << ans + n + 1 << endl;
        }
    }
    return 0;
}

