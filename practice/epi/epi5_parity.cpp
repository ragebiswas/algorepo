#include <iostream>
#include <string>
using namespace std;

int cache[1 << 16];

void precalc()
{
    for (int i = 0; i < (1 << 16); i++) {
        int p = 0, x = i;
        while (x) {
            p ^= 1;
            x &= (x - 1);
        }
        cache[i] = p;
    }
}

int fast_parity(int64_t n)
{
    int bitmask = 0xFFFF;
    int ws = 16;
    int ans = 0;
    ans =  cache[n & bitmask];
    ans ^= cache[(n >> ws) & bitmask];
    ans ^= cache[(n >> ws*2) & bitmask];
    ans ^= cache[(n >> ws*3) & bitmask];
    return ans;
}

int main()
{
    precalc();
    int64_t n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Parity: " << fast_parity(n) << endl;
    return 0;
}

