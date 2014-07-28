#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int t, lsqrt, gsqrt, xc, yc;
    while (1) {
        cin >> t;
        if (t == 0) {
            break;
        }
        lsqrt = int(sqrt(t));
        gsqrt = lsqrt + 1;

        if (lsqrt * lsqrt == t) {
            if (lsqrt % 2 == 0) {
                xc = lsqrt;
                yc = 1;
            }
            else {
                xc = 1;
                yc = lsqrt;
            }
        }
        else if (lsqrt % 2 == 0) {            
            xc = min(gsqrt * gsqrt - t + 1, gsqrt);
            yc = min(t - lsqrt * lsqrt, gsqrt);            
        }
        else {
            xc = min(t - lsqrt * lsqrt, gsqrt);
            yc = min(gsqrt * gsqrt - t + 1, gsqrt); 
        }
        cout << xc << " " << yc << endl;
    }
    return 0;
}