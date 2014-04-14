// Codechef April 14
// Trivial coding
#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n)
{
    if (n <= 1 || n % 2 == 0)  
        return false;
    if (n == 2)
        return true;
    int r = sqrt(n);
    for (int x = 3; x <= r; x += 2) {
        if (n % x == 0)
            return false;
    }
    return true;
}

int p[2500];

void precalc()
{
    for (int i = 2; i < 2500; i++) 
        p[i] = isprime(i);
}

int main()
{
    precalc();
    int ncases;
    cin >> ncases;
    while(ncases--) {
        int a, b;
        cin >> a >> b;
        int c = 1;
        while (1) {
            if (p[a + b + c]) {
                cout << c << endl;
                break;
            }
            c++;
        }
    }    
    return 0;
}
    