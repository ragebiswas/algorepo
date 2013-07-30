/*
 * SPOJ PRIME1
 * 
 * Basic algorithm: Use Sieve of Eratosthenes if the numbers lie within 1 million.
 * Else, use the Segmented Sieve algorithm
 * Reference: http://programmingpraxis.com/2010/02/05/segmented-sieve-of-eratosthenes/
 *
 */
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;
const int SIMPLE_MAX = 1000000;

class Sieve 
{
    private:
        static const int MAX = SIMPLE_MAX;
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


class SegmentedSieve 
{
    private:
        int L, R, B;

        // Stuff for base simple sieve primes
        vector<int> base_primes;
        vector<int> primes;
        static const int MAX = 1000000;
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
            int sqrtR = (int) sqrt(R);
            if(sqrtR >= L) {
                throw "sqrt(R) is >= L!";
            }
            base_sieve();
            segmented_sieve();
        }
        vector<int> get() {
            return primes;
        }
};


int main()
{
    int nc;
    cin>>nc;
    Sieve simplesieve;

    while(nc--) {
        int a, b;
        cin>>a>>b;
        vector<int> answers;

        // Try simple sieve if possible
        if(a < SIMPLE_MAX && b < SIMPLE_MAX) {
            answers = simplesieve.get(a, b);
        }
        else {
            // Segmented Sieve
            int l = (a/200)*200;
            int r = (b/200)*200 + 200;
            SegmentedSieve ss(l, r, 100);
            answers = ss.get();
        }

        // Print answers
        for(int i=0; i<answers.size(); i++) {
            if(answers[i] >= a && answers[i] <= b) {
                cout<<answers[i]<<endl;
            }
        }
        cout<<endl;
    }


    return 0;
}
