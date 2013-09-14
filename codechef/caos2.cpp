/**
 * Problem: http://www.codechef.com/SEPT13/problems/CAOS2
 * Category: Simple coding, basic math
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <map>
using namespace std;

class Sieve 
{
    private:
        static const int MAX = 4000;
        bitset<MAX> sieve;
        vector<int> primes;

    public:
        Sieve() 
        {
            primes.push_back(2); 

            for(int i=4; i<MAX; i+=2) {
                sieve[i] = 1;
            }
            int m = (int) sqrt(MAX);
            for(int i=3; i <= m; i++) {
                if(!sieve[i]) {
                    for(int j=i*i; j<MAX; j+=2*i) {
                        sieve[j] = 1;
                    }
                }
            }
            for(int i=3; i<MAX; i+=2) {
                if(!sieve[i]) {
                    primes.push_back(i);
                }
            }
        }
        vector<int> get(int l, int r) 
        {
            vector<int> ret;
            for(int i=0; i<primes.size(); i++) {
                if(primes[i] >= l && primes[i] <= r) {
                    ret.push_back(primes[i]);
                }                
            }
            return ret;
        }
};

const int MAX = 501;
int L[MAX][MAX];
int R[MAX][MAX];
int T[MAX][MAX];
int B[MAX][MAX];

void reset(int r, int c) 
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            L[i][j] = 0;
            R[i][j] = 0;
            T[i][j] = 0;
            B[i][j] = 0;
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    Sieve sieve;
    vector<int> primes = sieve.get(1, 4000);
    map<int, int> primehash;

    for(int i = 0; i < 500; i++)
        primehash[primes[i]] = i + 1;


    while (tc--) {
        int r, c;
        cin >> r >> c;
        reset(r, c);
        vector<string> m(r);

        for(int i = 0; i < r; i++) {
            cin >> m[i];
        }

        // L
        for(int i = 0; i < r; i++) {
            for(int j = 1; j < c; j++) {
                if(m[i][j - 1] == '^') {
                    L[i][j] = L[i][j - 1] + 1;
                } 
            }
        }

        // R
        for(int i = 0; i < r; i++) {
            for(int j = c - 2; j >= 0; j--) {
                if(m[i][j + 1] == '^') {
                    R[i][j] = R[i][j + 1] + 1;
                } 
            }
        }

        // T
        for(int j = 0; j < c; j++) {
            for(int i = 1; i < r; i++) {
                if(m[i - 1][j] == '^') {
                    T[i][j] = T[i - 1][j] + 1;
                }
            }
        }

        // B
        for(int j = 0; j < c; j++) {
            for(int i = r - 2; i >= 0; i--) {
                if(m[i + 1][j] == '^') {
                    B[i][j] = B[i + 1][j] + 1;
                }
            }
        }

        // Main logic
        int cnt = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(m[i][j] == '^') {
                    int l_ = L[i][j], r_ = R[i][j], t_ = T[i][j], b_ = B[i][j];
                    int minval = min(min(l_, r_), min(t_, b_));
                    int x = minval;
                    while(x > 1) {
                        if(primehash.find(x) != primehash.end()) {
                            cnt += primehash[x];
                            break;
                        }
                        x--;
                    }
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
