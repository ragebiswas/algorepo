#include <iostream>
using namespace std;

const int MAX = 100000;
int arr[MAX];

int main()
{
  int n;
  while(1)
  {
    cin>>n;
    bool ambiguous = true;
    
    if(n==0)
      break;
      
     for(int i=0; i<n; i++)
     {
        cin>>arr[i];
     }
     
     for(int i=0; i<n; i++)
     {
        if(arr[i] > n || arr[arr[i]-1] != (i+1))
        {
            ambiguous = false;
            break;
        }
     }
     
     cout<<(ambiguous ? "ambiguous" : "not ambiguous")<<endl; 
  }

  return 0;
}