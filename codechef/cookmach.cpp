#include <iostream>
using namespace std;

bool ispowerof2(unsigned int x) {
    return x && !(x & (x - 1));
}

int main()
{
    int nc, from, to;
    cin >> nc;
    while (nc--) {
        cin >> from >> to;
        int ans = 0; 
        while (from != to) {
            while (!ispowerof2(from)) {
                from /= 2;
                ans++;
            }
            if (from == to) {
                break;
            } 
            else if (from < to) {
                from *= 2;
            }
            else {
                from /= 2;
            }
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
