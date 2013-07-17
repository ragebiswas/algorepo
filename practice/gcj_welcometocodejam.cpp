#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

const int LEN = 50000;

using namespace std;

void print(int i)
{
  cout<<i;
}


string readline(ifstream& ifs)
{
  char line[LEN];
  ifs.getline(line, LEN);
  string s = line;
  return s;
}


string getcount(string s)
{
  int count = 1;
  char cstr[10];

  string ref = "welcome to code jam";
  vector<int> counts(ref.size(),0);
  char thischar, nextchar;
  int lastpos = 0;

  while(s[lastpos]!=ref[0] && lastpos < s.size())
    lastpos++;

  if(lastpos>=s.size()-1) 
    return "0000";

  for(int i=0; i<ref.size();i++)
  {
    thischar = ref[i];
    
    if(i!=ref.size()-1)
      nextchar=ref[i+1];
    else
      nextchar='-';

    for(int j=lastpos; j<s.size(); j++)
    {
      if(s[j]==nextchar)
      {
        lastpos = j;
        break;
      }

      if(s[j]==thischar)
        counts[i]++;
    }
  }


  for(int i=0;i<counts.size();i++)
  {
    count *= counts[i];
    count %= 10000;
  }

  cout<<ref<<endl;
  for_each(counts.begin(), counts.end(), print);

  sprintf(cstr, "%04d", count);
  return string(cstr);
}


int main()
{
      
  ifstream ifs;
  ifs.open("A-small.in");
  char str[LEN];

  ifs.getline(str, LEN);
  string s = str;
  istringstream iss(s);

  int N;
  iss>>N;

  for(int i=0; i<N; i++)
  {
    string s = readline(ifs);
    cout<<"Case #"<<i+1<<": "<<getcount(s)<<endl;
    //cout<<"Case #"<<i+1<<": "<<s<<":"<<getcount(s)<<endl;
  }

  return 0;
}
