#include <iostream>
#include <map>
using namespace std;

#define MAX 29000

bool abundant[MAX];

void init_abundant()
{
  for(int i=1; i<MAX; i++)
  {
    map<int, bool> m;
    int sum = 0;
    m[1] = true;
    
    for(int j=2; j*j <= i; j++)
    {
      if(i%j == 0)
      {
        int d = i/j;
        if(m.find(j) == m.end())
        {
          m[j] = true;
          sum += j;
        }
        
        if(m.find(d) == m.end())
        {
          m[d] = true;
          sum += d;
        }
      }
    }
    
    if(sum > i)
    {
      abundant[i] = true;
      //cout<<i<<" is abundant"<<endl;
    }
  }
  
  
}


int main()
{
  init_abundant();
  long long sum = 0;
  
  for(int i=1; i<MAX; i++)
  {
    bool possible = false;
    for(int j=1; j<i; j++)
    {
      if(abundant[j] && abundant[i-j])
      {
        possible = true;
        break;
      }
    }
    
    if(!possible)
    {
      //cout<<"Not possible for "<<i<<endl;
      sum += i;
    }   
    
  }
  
  cout<<"\nSum of all such integers: "<<sum<<endl;
}