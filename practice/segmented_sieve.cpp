#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

class SegmentedSieve 
{
private:
    int L, R, B;

    // Stuff for base simple sieve primes
    vector<int> base_primes;
    vector<int> primes;
    static const int MAX = 100000;
    bitset<MAX> sieve;

    // Mod utility
    int mod (int a, int b)
    {
        if(b < 0) {
            return mod(-a, -b);   
        }
        int ret = a % b;
        if(ret < 0) {
            ret+=b;
        }
        return ret;
    }

    // Build primes upto sqrt(R) using plain Sieve of Eratosthenes
    void base_sieve() {
        for(int i=4; i<MAX; i+=2) {
            sieve[i] = 1;
        }
        int sqrtR = (int) sqrt(R);
        for(int i=3; i*i < sqrtR; i++) {
            if(!sieve[i]) {
                for(int j=i*i; j<sqrtR; j+=2*i) {
                    sieve[j] = 1;
                }
            }
        }
        for(int i=3; i<sqrtR; i+=2) {
            if(!sieve[i]) {
                base_primes.push_back(i);
            }
        }
    }

    // Segmented Sieve of Eratosthenes algorithm
    void segmented_sieve() {        
        int l = L;

        while(l + 2*B <= R) {
            vector<bool> bits(B, 1);
            for(int k=0; k<base_primes.size(); k++) {
                int pk = base_primes[k];
                int q = mod( (-1 * (l + 1 + pk) / 2), pk);
                while(q < B) {
                    bits[q] = 0;
                    q += pk;
                }
            }

            for(int i=0; i<B; i++) {
                if(bits[i] == 1) {
                    primes.push_back(l+2*i+1);
                }
            }

            l += 2*B;
        }   
    }
public:
    SegmentedSieve(int l, int r, int b) : L(l), R(r), B(b) {
        if((R-L) % (2*B) != 0) {
            throw "2B must divide (R-L)!";
        }
        base_sieve();
        segmented_sieve();
    }
    vector<int> get() {
        return primes;
    }
};

int main() {
    SegmentedSieve ss(100, 300, 50);
    vector<int> primes = ss.get();
    for(int i=0; i<primes.size(); i++) {
        cout<<"Prime: "<<primes[i]<<endl;
    }
}
