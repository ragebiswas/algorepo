#include <iostream>
using namespace std;

int main()
{
  int nc, n;
  unsigned int res;
  cin>>nc;
  while(nc--)
  {
    cin>>n;
    res = 1;
    while(res <= n)
      res<<=1;
    cout<<(res>>1)<<endl;
  }
  return 0;
}