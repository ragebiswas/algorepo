#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

#define MAX 4
typedef long long int64;
vector<int64> pals, ans;

inline void gen(int64 lo, int64 hi)
{
    for(int64 n=lo; n<=hi; n++)
    {
        int64 tmp = n, x = n;
        while(tmp)
        {
            int d = tmp%10;
            x = x*10 + d;
            tmp /= 10;
        }
        pals.push_back(x);
    }

    for(int64 n=lo; n<=hi; n++)
    {
        for(int64 mid=0; mid<=9; mid++)
        {
            int64 tmp = n, x = n;
            x = x*10 + mid;

            while(tmp)
            {
                int d = tmp%10;
                x = x*10 + d;
                tmp /= 10;
            }
            pals.push_back(x);
        }
    }
}

inline bool ispal(int64 n)
{
    char s[20];
    sprintf(s, "%lld", n);
    int len = strlen(s);
    for(int i=0; i<len; i++)
        if(s[i] != s[len-i-1])
            return false;
    
    return true;
}

int main()
{
    for(int i=1; i<=9; i++)
        pals.push_back(i);
        
    int64 tens = 1;
    for(int i=1; i<=MAX; i++)
    {
        int64 lo = tens;
        int64 hi = tens*10-1;
        tens*= 10;
        gen(lo, hi);
    }

    for(int i=0; i<pals.size(); i++)
    {
        int64 t = pals[i]*pals[i];
        if(ispal(t))
            ans.push_back(t);
    }
    
    int nc;
    cin>>nc;
    for(int c=1; c<=nc; c++)
    {
        int64 l, u;
        cin>>l>>u;
        int tot = 0;
        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i] >= l && ans[i] <= u)
            {
                tot++;
            }
        }
        cout<<"Case #"<<c<<": "<<tot<<endl;
    }

    return 0;
}