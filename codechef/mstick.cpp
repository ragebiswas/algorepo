#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vvi;

static inline int log2(unsigned int n)
{
    unsigned int r = 0;
    while(n >>= 1)
        r++;
    return r;
}

class RangeMinimumQuery
{
private:
    vi A;
    vvi M;

public:
    RangeMinimumQuery(vi a) : A(a)
    {
        int logn = log2(a.size())+1;
        vi mrow(logn, 0);
        vvi _M(a.size(), mrow);
        M = _M;
        preprocess();
    }

    void preprocess()
    {
        unsigned int i, j;
        int N = A.size();

        for(i=0; i<N; i++)
            M[i][0] = i;

        for(j=1; 1 << j <= N; j++)
        {
            for (i = 0; (i + (1 << j) - 1) < N; i++)
            {
                if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                    M[i][j] = M[i][j - 1];
                else
                    M[i][j] = M[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query(int i, int j)
    {
        int k  = log2(j-i+1);
        if (A[M[i][k]] <= A[M[j - (1 << k) + 1][k]])
            return M[i][k];
        else
            return M[j - (1 << k) + 1][k];
    }


};

class RangeMaximumQuery
{
private:
    vi A;
    vvi M;

public:
    RangeMaximumQuery(vi a) : A(a)
    {
        int logn = log2(a.size())+1;
        vi mrow(logn, 0);
        vvi _M(a.size(), mrow);
        M = _M;
        preprocess();
    }

    void preprocess()
    {
        unsigned int i, j;
        int N = A.size();

        for(i=0; i<N; i++)
            M[i][0] = i;

        for(j=1; 1 << j <= N; j++)
        {
            for (i = 0; (i + (1 << j) - 1) < N; i++)
            {
                if (A[M[i][j - 1]] > A[M[i + (1 << (j - 1))][j - 1]])
                    M[i][j] = M[i][j - 1];
                else
                    M[i][j] = M[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query(int i, int j)
    {
        int k  = log2(j-i+1);
        if (A[M[i][k]] >= A[M[j - (1 << k) + 1][k]])
            return M[i][k];
        else
            return M[j - (1 << k) + 1][k];
    }


};

int getmin(int left, int right, RangeMinimumQuery& rmq, vi& arr, int &idx)
{
    assert(left <= right && left >=0 && right < arr.size());
    
    if(left == right)
    {
        idx = left;
        return arr[left];
    }
    
    idx = rmq.query(left, right);
    return arr[idx];
}

int getmax(int left, int right, RangeMaximumQuery& rmq, vi& arr, int& idx)
{
    if(left > right || left < 0 || right >= arr.size())
        return 0;
        
    if(left == right)
    {
        idx = left;
        return arr[left];
    }
        
    idx = rmq.query(left, right);
    return arr[idx];
}

int main()
{
    int n,q,l,r;
    cin>>n;
    vi a(n, 0);
    for(int i=0; i<n; i++)
        cin>>a[i];

    RangeMinimumQuery rminq(a);
    RangeMaximumQuery rmaxq(a);

    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        int tmp;
        
        int minindex = -1;
        int mintime = getmin(l, r, rminq, a, minindex);
        
        int maxouts = 0;
        maxouts = max(maxouts, getmax(0, l-1, rmaxq, a, tmp));
        maxouts = max(maxouts, getmax(r+1, a.size()-1, rmaxq, a, tmp));
       
        int maxins = 0;
        maxins = max(maxins, getmax(l, minindex-1, rmaxq, a, tmp));
        maxins = max(maxins, getmax(minindex+1, r, rmaxq, a, tmp));
        
        double tmaxout = mintime + maxouts;
        double tmaxin = mintime + (maxins-mintime)*1.0/2.0;
        
        cout.setf(std::ios::fixed);
        cout.precision(1);
        cout<<max(tmaxin, tmaxout)<<endl;
    }

    return 0;
}
