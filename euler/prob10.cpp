#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>

using namespace std;

const int MAX = 1000000001;

bitset<MAX> primes(1);

void buildprimes()
{
  for(int i=0; i<MAX; i++) 
    primes[i] = 1;

  int start = 2;
  int lastunset;

  primes[1] = 0;

  while(start*start < MAX)
  {
    int j = start*start;
    while(j < MAX)
    {
      primes[j] = 0;
      j += start;
    }

    start++;
    while(primes[start] == 0)
      start++;
  }
}


int main()
{
  buildprimes();
  long long sum = 0;

  for(int i=1; i<MAX; i++) 
    if(primes[i]) 
    {
      sum += i;
    }

  cout<<"Sum: "<<sum<<endl;
  return 0;
}
