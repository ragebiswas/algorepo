#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nc;
    cin >> nc;
    while (nc--) {
        int n, k, ne = 0, tmp;
        bool ho = false;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp % 2 == 0) {
                ne++;
            }
            else {
                ho = true;
            }
        }
        if (k == 0) {
            cout << ((ho) ? "YES" : "NO") << endl;
        }
        else {
            cout << ((k <= ne) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}