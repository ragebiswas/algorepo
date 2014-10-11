// Codechef Oct 2014
#include <iostream>
using namespace std;

int main()
{
    int nc;
    cin >> nc;
    while (nc--) {
        int n, m, t;
        int mx = 0, sum = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> t;
            mx = max(mx, t);
            sum += t; 
        }
        if (((sum + m) % n == 0) && (mx <= ((sum + m) / n))) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}
