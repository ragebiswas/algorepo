#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

const int MAX=1000001;
bool sieve[MAX];

void eratosthenes()
{
    int crosslimit = int(sqrt(MAX));

    // mark even numbers
    for(int i=4; i<MAX; i+=2)
        sieve[i] = true;

    // sieve it
    for(int i=3; i<=crosslimit; i++)
    {
        if(!sieve[i])
        {
            for(int j=i*i; j<MAX; j+=2*i)
                sieve[j] = true;
        }
    }
}



int main() {
    int nc;
    cin>>nc;    
    eratosthenes();
    vector<int> primes;

    for(int i=2; i<MAX; i++) {
        if(sieve[i] == false) {
            primes.push_back(i);
        }        
    }

    while(nc--) {
        vector<int> counts(primes[primes.size()-1], 0);        
        int n;
        cin>>n;
        while(n--) {
            int num;
            cin>>num;
            while(num != 1) {
                for(int i=0; i<primes.size() && num != 1; i++) {
                    if(num % primes[i] == 0) {
                        num /= primes[i];
                        counts[primes[i]]++;
                    }
                }
            }
        }
        long long res = 1;
        for(int i=0; i < counts.size(); i++) 
            if(counts[i] != 0)
                res *= (counts[i] + 1);
        cout<<res<<endl;
    }

}