#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long ans, alloc;
    int nc, ne, e;
    cin >> nc;
    while (nc--) {
        cin >> ne;
        ans = 0;
        alloc = 0;
        for (int i = 0; i < ne; i++) {
            cin >> e;
            if (e > alloc) {
                ans += (e - alloc);
                alloc = e;
            }
            else {
                alloc = e;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
