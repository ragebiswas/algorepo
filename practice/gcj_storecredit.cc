#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;


void solve(int ncase, int sc, vector<int>& items)
{
  cout<<"Case #"<<ncase<<": ";

  map<int, int> m;
  for(int i = 0; i < items.size(); i++) 
  {
    m[items[i]] = i;
  }

  int a, i,j;

  for(i = 0; i < items.size(); i++)
  {
    a = items[i];
    if(m.find(sc-a) != m.end())
    {
      if(m[sc-a] == i) 
      {
        // same index
        continue;
      }
      
      j = m[sc-a];
      break;
    }
  }

  cout<<i+1<<" "<<j+1<<endl;
}


int main()
{
  vector<int> items;
  char line[10000];
  char num[10];

  fstream inputfile("A-large-practice.in", ios::in);
  inputfile.getline(num, 10);

  int ncases = 0;
  istringstream i(num);
  i>>ncases;

  int sc = 0;
  int nitems = 0;
  int ncase = 1;

  while(!inputfile.eof() && ncases--)
  {
    // read store credit
    inputfile.getline(num, 10);
    istringstream j(num);
    j>>sc;

    // read nitems
    inputfile.getline(num, 10);
    istringstream k(num);
    k>>nitems;

    // read items
    vector<int> items;
    inputfile.getline(line, 10000);
    istringstream l(line);
    for(int c = 0; c < nitems; c++)
    {
      int t;
      l>>t;
      items.push_back(t);
    }

    // solve
    solve(ncase, sc, items);
    ncase++;
  }

  return 0;
}

