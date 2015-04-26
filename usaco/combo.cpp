/*
ID: rajorsh2
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

struct C {
    int x;
    int y;
    int z;
};

bool operator < (const C & lhs, const C & rhs) {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    if (lhs.y != rhs.y) return lhs.y < rhs.y;
    return lhs.z < rhs.z;
}

int mod(int i, int N)
{
    int f = (N + i) % N;
    if (f == 0) f = N;
    return f;
}

int main()
{
    ifstream cin("combo.in");
    ofstream cout("combo.out");
    int N;
    cin >> N;
    int combo[3], mcombo[3];
    for (int i = 0; i < 3; i++) {
        cin >> combo[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> mcombo[i];
    }
    map<C, int> ans;
    C c;

    /* calculate for 'combo' */
    for (int x = (combo[0] - 2) ; x <= (combo[0] + 2) ; x++) {
        for (int y = (combo[1] - 2) ; y <= (combo[1] + 2) ; y++) {
            for (int z = (combo[2] - 2) ; z <= (combo[2] + 2) ; z++) {
                c.x = mod(x, N);
                c.y = mod(y, N);
                c.z = mod(z, N);
                //cout << c.x << ", " << c.y << ", " << c.z << endl;
                ans[c] = 1;
            }
        }
    }
    /* calculate for 'mcombo' */
    for (int x = (mcombo[0] - 2) ; x <= (mcombo[0] + 2) ; x++) {
        for (int y = (mcombo[1] - 2) ; y <= (mcombo[1] + 2) ; y++) {
            for (int z = (mcombo[2] - 2) ; z <= (mcombo[2] + 2) ; z++) {
                c.x = mod(x, N);
                c.y = mod(y, N);
                c.z = mod(z, N);
                //cout << c.x << ", " << c.y << ", " << c.z << endl;
                ans[c] = 1;
            }
        }
    }
 
    cout << ans.size() << endl;

    return 0;
}

