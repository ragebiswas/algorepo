#include <iostream>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
  ifstream fin(argv[1]);
  vector<int> v;
  int i, n;
  
  while(fin>>n)
  {
    v.push_back(n);
  }
  
  int sz = v.size();
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
  
  cout<<s.size()<<endl;
  return 0;
}