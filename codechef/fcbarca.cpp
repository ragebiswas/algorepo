#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef vector<long long> vi;
typedef vector<vector<long long> > vvi;
#define MOD 1000000007 

vvi matmult(const vvi& a, const vvi& b)
{
    vi row(b[0].size(), 0);
    vvi res(a.size(), row);

    for(int i=0; i<a.size(); i++)
        for(int j=0; j<b[0].size(); j++)
            for(int k=0; k<a[0].size(); k++)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
    
    return res;
}

vvi matpow(const vvi& a, int p)
{
    if(p == 1) 
        return a;
    vvi tmp = matpow(a, p/2);
    if(p%2 == 1)
        return matmult(a, matmult(tmp, tmp));
    else
        return matmult(tmp, tmp);
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        long long n, k;
        cin>>n>>k;

        vi row(k+1, 1);
        vvi mat(k+1, row);

        for(int i=0; i<k+1; i++)
            mat[i][i] = 0;

        vvi res = matpow(mat, n);
        cout<<res[0][0]<<endl;
    }

    return 0;
}