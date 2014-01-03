/**
 * Problem: http://www.codechef.com/JAN14/problems/PLZLYKME
 * Category: Basic math (binomial coefficients)
 */

#include <iostream>
using namespace std;
uint64_t l, d, s, c;

// Fast exponentiation, but return 0 whenever result exceeds 'l'
uint64_t fast_exp(uint64_t a, uint64_t b){
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        if (a >= l) return 0;
        return a;
    }
    if (b == 2) {
        if (a >= l) return 0;
        return a*a;
    }

    if (b % 2 == 0){
        return fast_exp(fast_exp(a, b / 2), 2);
    }
    else{
        return a*fast_exp(fast_exp(a, (b - 1) / 2), 2);
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> l >> d >> s >> c;
        // final formula = s * ((c + 1) ^ (d - 1))
        uint64_t tmp = fast_exp(c + 1, d - 1) * s;
        if (tmp >= l || tmp == 0)
            cout << "ALIVE AND KICKING\n";
        else
            cout << "DEAD AND ROTTING\n";
    }
    return 0;
}
