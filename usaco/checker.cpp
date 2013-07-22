/*
ID: rajorsh2
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 13

int board[MAX][MAX];
int inval[MAX][MAX];
int soln[MAX];
int ans[3][MAX];
int hascol[MAX];
int ldiag[MAX*2+1];
int rdiag[MAX*2+1];
int n, total;

void init()
{
    total = 0;

    for(int r = 0; r < n; r++)
    {
        hascol[r] = 0;
        for(int c = 0; c < n; c++)
            board[r][c] = 0;
    }
}

void save()
{
    total++;

    if(total > 3)
        return;

    for(int i = 0; i < n; i++)
        ans[total - 1][i] = soln[i];
}

inline bool validpos(const int& r, const int& c)
{
    return (r >= 0 && r < n && c >= 0 && c < n);
}


inline bool valid(int row, int col)
{
    if(hascol[col])
        return false;

    if(ldiag[MAX + row-col])
        return false;

    if(rdiag[row+col])
        return false;

    return true;
}

inline void mark(int row, int col, int val)
{
    hascol[col] = val;
    ldiag[MAX + row-col] = val;
    rdiag[row+col] = val;
}

void solve(int r)
{
    if(r == n)
    {
        save();
        return;
    }

    for(int c = 0; c < n; c++)
    {
        if(valid(r, c))
        {
            soln[r] = c;
            board[r][c] = 1;
            mark(r,c,1);

            solve(r + 1);

            soln[r] = 0;
            board[r][c] = 0;
            mark(r,c,0);
        }
    }
}


int main()
{
    ifstream cin("checker.in");
    ofstream cout("checker.out");

    cin>>n;
    init();
    solve(0);

    for(int i = 0; i < min(3, total); i++)
    {
        for(int j = 0; j < n - 1; j++)
            cout << ans[i][j] + 1 << " ";

        cout << ans[i][n - 1] + 1 << endl;
    }

    cout << total << endl;

    return 0;
}
