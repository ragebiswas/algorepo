/**
 * Problem: http://www.codechef.com/NOV13/problems/MCHAIRS/
 * Category: Simple math
 */
#include <iostream>
using namespace std;
const int M = 1000000007;

int64_t modpow(int64_t base, int64_t exp, int64_t modulus)
{
    base %= modulus;
    int64_t result = 1;
    while (exp > 0)
    {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main()
{
    int64_t nc, n;
    cin >> nc;
    while(nc--) {
        cin >> n;
        cout << modpow(2, n, M) - 1 << endl;
    }
    return 0;
}