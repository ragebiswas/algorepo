#include <iostream>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int lis(vector<int>& v)
{
  int sz = v.size();
  int i;
  set<int> s;
  set<int>::iterator it;
  
  for(i=0; i<sz; i++)
  {
    if(s.insert(v[i]).second)
    {
      it = s.find(v[i]);
      it++;
      if(it != s.end())
        s.erase(it);
    }
  }
  
  return s.size();
}

int main(int argc, char** argv)
{
  ifstream fin(argv[1]);
  vector<int> v;
  int n;
  
  while(fin>>n)
  {
    v.push_back(n);
  }
  
  cout<<lis(v)<<endl;
  return 0;
}