#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

const int LEN = 500000;

using namespace std;


void print(int i)
{
  cout<<i<<" ";
}

void solve(vector<int> v1, vector<int> v2)
{
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  reverse(v2.begin(),v2.end());

  long long sum = 0;

  for(int i=0; i<v1.size();i++)
  {
    sum += (long long)v1[i] * (long long)v2[i];
  }

  cout<<sum<<endl;
}


int main()
{
  ifstream ifs;
  ifs.open("A-small.in");
  char str[LEN];
  int nc = 0;

  ifs.getline(str, LEN);
  string s = str;
  istringstream iss(s);
  iss>>nc;
  int c = 1;

  while(nc--)
  {
    ifs.getline(str, LEN);
    string nn = str;
    int n;
    istringstream iss2(nn);
    iss2>>n;

    char vec1[LEN], vec2[LEN];
    ifs.getline(vec1, LEN);
    ifs.getline(vec2, LEN);

    string svec1=vec1;
    string svec2=vec2;

    vector<int> v1,v2;

    cout<<"Case #"<<c++<<": ";

    istringstream vs1(svec1);
    istringstream vs2(svec2);

    for(int i = 0; i<n; i++)
    {
      int n1, n2;
      vs1>>n1;
      vs2>>n2;
      v1.push_back(n1);
      v2.push_back(n2);
    }

    solve(v1,v2);
  }

  return 0;
}
