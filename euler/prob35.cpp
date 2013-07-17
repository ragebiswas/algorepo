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


bool checkrots(int n)
{
  ostringstream oss;
  oss<<n;
  string str = oss.str();
  string rot = str;
  int sz = str.size();
  string es = "";
  int v;
  
  do
  {
    rot = es + rot[sz-1] + rot.substr(0, sz-1);
    istringstream iss(rot);
    iss>>v;
    if(sieve[v])
      return false;
  
  } while(rot != str);
  

  
  return true;
  
}


int main()
{
  eratosthenes();
  
  int n = 0;
  for(int i=2; i<1000000; i++)
  {
    if(!sieve[i] && checkrots(i))
    {
      cout<<"Circular prime: "<<i<<endl;
      n++;
    }
  }
  
  cout<<"\nTotal: "<<n<<endl;
}