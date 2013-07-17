#include <iostream>
#include <string>
#include <vector>

using namespace std;

void process(const string& p, const string& c)
{
    vector<int> pmap(26, 0), cmap(26, 0);
    for(int i=0; i<p.size(); i++)
    {
        pmap[p[i]-'a']++;
    }
    for(int i=0; i<c.size(); i++)
    {
        cmap[c[i]-'a']++;
    }
    bool ans = true;
    for(int i=0; i<26; i++)
    {
        if(cmap[i] > pmap[i])
        {
            ans = false;
            break;
        }
    }
    
    ans ? cout<<"YES\n" : cout<<"NO\n";
    return;
}


int main()
{
    int nc, n;
    cin>>nc;
    string a, b, c;
    
    while(nc--)
    {
        cin>>a>>b;
        cin>>n;
        c = "";
        
        while(n--)
        {
            string tmp;
            cin>>tmp;
            c += tmp;            
        }
        process(a+b, c);
    }
   
    return 0;
}