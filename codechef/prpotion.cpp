// Codechef Oct 2014
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int rn, gn, bn, m, t;
        int rmax = 0, gmax = 0, bmax = 0;
        cin >> rn >> gn >> bn >> m;
        for (int i = 0; i < rn; i++) {
            cin >> t;
            rmax = max(t, rmax);
        }
        for (int i = 0; i < gn; i++) {
            cin >> t;
            gmax = max(t, gmax);
        }
        for (int i = 0; i < bn; i++) {
            cin >> t;
            bmax = max(t, bmax);
        }
        for(int i=0; i < m; i++) {
            if (rmax >= gmax && rmax >= bmax) {
                rmax /= 2;
            }
            else if (gmax >= rmax && gmax >= bmax) {
                gmax /= 2;
            }
            else if (bmax >= rmax && bmax >= gmax) {
                bmax /= 2;
            }
        }
        cout << max(rmax, max(gmax, bmax)) << endl;
    }

    return 0;
}
