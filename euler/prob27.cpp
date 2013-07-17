#include <string>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
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

int getmax(int a, int b)
{
  int primes = 0;
  int n = 0;
  int v;
  
  while(1)
  {
    v = n*n + a*n + b;
    if(sieve[v] || v < 2)
      break;

    n++;
    primes++;
  }
  
  return primes;  
  
}



int main()
{
  eratosthenes();
  int maxcount = 0;
  int pc, tmc, ma, mb;

  for(int a=0; a<1000; a++)
  {
    for(int b=0; b<1000; b++)
    {
      tmc = getmax(a, b);
      if(tmc > maxcount)
      {
        ma = a;
        mb = b; 
        maxcount = tmc;
      }
      
      tmc = getmax(-a, b);
      if(tmc > maxcount)
      {
        ma = -a;
        mb = b; 
        maxcount = tmc;
      }
      
      tmc = getmax(a, -b);
      if(tmc > maxcount)
      {
        ma = a;
        mb = -b; 
        maxcount = tmc;
      }
      
      tmc = getmax(-a, -b);
      if(tmc > maxcount)
      {
        ma = -a;
        mb = -b; 
        maxcount = tmc;
      }      
    }
  }

  cout<<"Maxcount = "<<maxcount<<endl;
  cout<<"a: "<<ma<<", b: "<<mb<<", p: "<<ma*mb<<endl;
  
}