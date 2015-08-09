#include <iostream>
using namespace std;

int main()
{
    long long int nc, x, y, xmin, xmax, ymin, ymax;
    cin >> nc;
    while (nc--) {
        cin >> x >> y;
        bool ans = false;   
        if (x == 0 && y == 0) {
            ans = true;
        }
        if ((x < 0) && (-x % 2 == 0)) {
            ymin = x; ymax = -x;
            if (y >= ymin && y <= ymax) {
                ans = true;
            }
        }
        if ((x > 0) && (x % 2 == 1)) {
            ymin = -1 * (x - 1); ymax = x + 1;
            if (y >= ymin && y <= ymax) {
                ans = true;
            }
        }
        if ((y > 0) && (y % 2 == 0)) {
            xmin = -y; xmax = y - 1;
            if (x >= xmin && x <= xmax) {
                ans = true;
            }
        }
        if ((y < 0) && (-y % 2 == 0)) {
            xmin = y; xmax = -1 * y + 1;
            if (x >= xmin && x <= xmax) {
                ans = true;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}