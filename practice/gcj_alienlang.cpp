#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

const int LEN = 50000;

using namespace std;

void print(string i)
{
  cout<<i<<endl;
}


string readline(ifstream& ifs)
{
  char line[LEN];
  ifs.getline(line, LEN);
  string s = line;
  return s;
}

bool match(string& word, string& pattern)
{

  int wpos = 0;

  for(int i=0; i<pattern.size(); i++)
  {
    if(pattern[i] == '(')
    {
      vector<char> possiblechars;
      int j;
      for(j=i+1; j<pattern.size() && pattern[j] != ')';j++)
      {
        possiblechars.push_back(pattern[j]);
      }

      bool possmatch = false;
      for(int k = 0; k<possiblechars.size(); k++)
      {
        if(possiblechars[k] == word[wpos])
        {
          possmatch = true;
          break;
        }
      }

      if(!possmatch)
        return false;

      i = j;
    }
    else
    {
      if(pattern[i] != word[wpos]) 
        return false;
    }
    wpos++;
  }

  return true;
}



int main()
{
      
  ifstream ifs;
  ifs.open("A-small.in");
  char str[LEN];

  ifs.getline(str, LEN);
  string s = str;
  istringstream iss(s);

  int L, D, N;
  iss>>L;
  iss>>D;
  iss>>N;

  vector<string> words;

  for(int i=0; i<D; i++)
  {
    string s = readline(ifs);
    words.push_back(s);
  }

  for(int i=0; i<N; i++)
  {
    string cur = readline(ifs);
    int nmatch = 0;

    for(int j=0; j<words.size(); j++)
    {
      // see how many match
      if(match(words[j], cur))
        nmatch++;
    }

    cout<<"Case #"<<i+1<<": "<<nmatch<<endl;
  }

  return 0;
}
