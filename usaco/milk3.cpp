/*
ID: rajorsh2
PROG: milk3
LANG: C++
*/
#include <vector>
#include <iostream>
#include <queue>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <sstream>

using namespace std;
int A, B, C;

struct state
{
    int a;
    int b;
    int c;
    state(int p, int q, int r)
    {
        a = p;
        b = q;
        c = r;
    }
    int hash()
    {
        return a*10000 + b*100 + c;
    }
    inline int get(int idx)
    {
        switch(idx)
        {
        case 0: return a;
        case 1: return b;
        case 2: return c;
        }
        return -1;
    }
    inline int getcap(int idx)
    {
        switch(idx)
        {
        case 0: return A;
        case 1: return B;
        case 2: return C;
        }
        return -1;
    }
    inline void set(int idx, int val)
    {
        switch(idx)
        {
        case 0: a = val; break;
        case 1: b = val; break;
        case 2: c = val; break;
        }
    }
};

map<int, bool> states;
map<int, bool> answers;
void solve(state);

inline void process(state s, int sidx, int didx)
{
    int destcap = s.getcap(didx);
    int src = s.get(sidx);
    int dest = s.get(didx);

    int avl = destcap - dest;
    if(avl == 0)
        return;

    int pour = min(avl, src);

    if(pour == 0)
        return;

    src -= pour;
    dest += pour;

    s.set(sidx, src);
    s.set(didx, dest);

    solve(s);
}

void solve(state s)
{
    if(s.a == 0)
        answers[s.c] = true;

    if(states.find(s.hash()) != states.end())
        return;

    states[s.hash()] = true;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i!=j)
            {
                process(s, i, j);
            }
        }
    }


}

int main()
{
    ifstream cin("milk3.in");
    ofstream cout("milk3.out");

    cin>>A>>B>>C;

    state init(0, 0, C);
    solve(init);

    vector<int> ans;
    for(map<int, bool>::iterator it = answers.begin(); it != answers.end(); ++it)
        ans.push_back(it->first);


    for(int i=0; i<ans.size() - 1; i++)
        cout<<ans[i]<<" ";
    cout<<ans[ans.size()-1]<<endl;

    return 0;
}