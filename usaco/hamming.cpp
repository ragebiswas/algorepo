/*
ID: rajorsh2
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int bitcount(int a)
{
    int ret = 0;
    while (a) {
        if (a & 01) {
            ret++;
        }
        a >>= 1;
    }
    return ret;
}

int get_hamming(int a, int b)
{
    return bitcount(a ^ b);
}

int mat[256][256], lim;

void printans(vector<int>& ans)
{
    ofstream cout("hamming.out");
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++) {        
        if (i % 10 == 0) {
            cout << "\n"; 
        } 
        else {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << endl;
}

int main()
{
	ifstream cin("hamming.in");
    int n, b, d;
    cin >> n >> b >> d;

    lim = 1 << b;
    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < lim; j++) {
            mat[i][j] = 0;
            if (get_hamming(i, j) >= d) {
                mat[i][j] = 1;
            }
        }
    }

    vector<int> ans;
    for (int t = 0; t < lim; t++) {
        if (ans.size() == 0) {
            ans.push_back(t);
        }
        else {
            bool valid = true;
            for (int i = 0; i < ans.size(); i++) {
                if (mat[t][ans[i]] == 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans.push_back(t);
                if (ans.size() == n) {
                    printans(ans);
                    exit(0);
                }
            }
        }
    }

    return 0;

}
