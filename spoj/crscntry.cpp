#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

const int MAX = 10000;

void print(int i)
{
    cout<<i<<" ";
}

string readline()
{
    char line[MAX];
    cin.getline(line, MAX);
    string str(line);
    return str;
}

int computelcs(vector<int> a, vector<int> b)
{
    vector< vector<int> > dp;
    for(int i = 0; i < a.size()+1; i++)
    {
        vector<int> t;
        for(int j=0; j<b.size()+1; j++)
        {
            t.push_back(0);
        }
        dp.push_back(t);
    }
    
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b.size(); j++)
        {
            if(a[i] == b[j])
            {
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else
            {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    
    return dp[a.size()][b.size()];
}

int main()
{
    int ncases;
    string ncstr = readline();
    istringstream i(ncstr);
    i>>ncases;
   
    vector<int> aroute;
    
    while(ncases--)
    {
        string agnesstr = readline();
        istringstream iss(agnesstr);
        int lcs = INT_MIN;
        
        aroute.clear();
        
        int r;
        while(iss>>r && r!=0)
        {
            aroute.push_back(r);
        }
        
        while(1)
        {
            string dudestr = readline();
            istringstream ds(dudestr);
            int r;
            ds>>r;
            
            if(r==0) break; // next test case
            vector<int> broute;
            broute.push_back(r);
            
            while(ds>>r && r!=0)
                broute.push_back(r);
            
            int tlcs = computelcs(aroute,broute);
            if(tlcs >= lcs)
                lcs=tlcs;
        }
        
        cout<<lcs<<endl;
        
    }
    return 0;
}




