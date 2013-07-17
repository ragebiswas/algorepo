#include <iostream>
#include <string>
#include <vector>

using namespace std;
int cpos[26][25000];

bool subsequence(const string& a, const string& b)
{
    vector<int> idx(26, 0);
    vector<int> midx(26, 0);

    for(int i=0; i<b.size(); i++)
    {
        int offset = b[i]-'a';
        int oldidx = midx[offset];
        cpos[offset][oldidx] = i;
        midx[offset]++;
    }

    bool ans = true;
    int last = -1;

    for(int i=0; i<a.size(); i++)
    {
        int offset = a[i]-'a';
        int maxidx = midx[offset];
        int tidx = idx[offset];
        bool found = false;
        while(tidx < maxidx)
        {
            int fpos = cpos[offset][tidx];
            if(fpos <= last)
            {
                tidx++;
                continue;
            }
            else
            {
                found = true;
                last = fpos;
                idx[offset]++;
                tidx++;
                break;
            }
        }

        if(found == false)
        {
            ans = false;
            break;
        }
    }

    return ans;
}


int main()
{
    int nc, n;
    cin>>nc;
    string a, b;

    while(nc--)
    {
        cin>>a>>b;
        if(a.size() > b.size())
            swap(a, b);

        subsequence(a, b) ? cout<<"YES\n" : cout<<"NO\n";
    }

    return 0;
}