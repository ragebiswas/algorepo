#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define LEN 1000000
#define INPUT "B-large.in"

void print(string i)
{
  cout<<i<<endl;
}

static string readline(ifstream& ifs)
{
  char line[LEN];
  ifs.getline(line, LEN);
  string s = line;
  return s;
}

static string fmt(string res)
{
	int sz = res.size();
	string ret = "[";
	for(int i=0;i<sz;i++)
	{
		ret += res[i];
		if(i<sz-1) 
			ret += ", ";
	}
	ret += "]";
	return ret;
}

int main()
{
      
  ifstream ifs;
  ifs.open(INPUT);

  int ncases = 0;
  string ncases_str = readline(ifs);
  istringstream iss(ncases_str);
  iss>>ncases;
  
  for(int nc=0; nc<ncases; nc++)
  {
    string tc = readline(ifs);
    istringstream iss(tc);
    
    int c;
    iss>>c;
    map<string, char> conversions;
    string es = "";
    
    for(int i=0;i<c;i++)
    {
        string conv;
        iss>>conv;        
        conversions[es + conv[0] + conv[1]] = conv[2];
        conversions[es + conv[1] + conv[0]] = conv[2];
    }
    
    int d; 
    iss>>d;
    map<string, bool> opposed;
    
    for(int i=0;i<d;i++)
    {
        string opp;
        iss>>opp;
        opposed[es + opp[0] + opp[1]] = true;
        opposed[es + opp[1] + opp[0]] = true;
    }
    iss>>d; // dummy
    
    string s;
    iss>>s;
    
    string res = es;
    int j = 0;
    res += s[0];
    
    for(int i=1; i<s.size();i++)
    {
        if((j>=0) && conversions.find(es+s[i]+res[j]) != conversions.end())
        {
            res[j] = conversions[es+s[i]+res[j]];
            continue;
        }
            
        bool cleared = false;
        for(int k=0;k<=j;k++)
        {
            if(opposed.find(es+s[i]+res[k]) != opposed.end())
            {
                res = es;
                j = -1;
                cleared = true;
                break;
            }
        }
        
        if(!cleared)
        {
            res += s[i];
            j++;
        }
    }  
   
    cout<<"Case #"<<nc+1<<": "<<fmt(res)<<endl;
  }

  return 0;
}
