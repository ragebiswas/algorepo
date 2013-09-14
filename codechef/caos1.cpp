/**
 * Problem: http://www.codechef.com/SEPT13/problems/CAOS1
 * Category: Simple coding
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        int r, c;
        cin >> r >> c;
        vector<string> m(r);

        for(int i = 0; i < r; i++) {
            cin >> m[i];
        }

        int tot = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(m[i][j] == '#') {
                    continue; 
                }

                int L = 0, R = 0, T = 0, B = 0;

                // Left
                for(int t = j; t >= 0; t--) {
                    if(m[i][t] == '^')
                        L++;
                    else 
                        break;
                }
                // Right
                for(int t = j; t < c; t++) {
                    if(m[i][t] == '^')
                        R++;
                    else 
                        break;
                }
                // Up
                for(int t = i; t >= 0; t--) {
                    if(m[t][j] == '^')
                        T++;
                    else 
                        break;
                }
                // Down
                for(int t = i; t < r; t++) {
                    if(m[t][j] == '^')
                        B++;
                    else 
                        break;
                }
                L--; 
                R--;
                T--;
                B--;
                int min_lr = min(L, R);
                int min_tb = min(T, B);
                int min_all = min(min_lr, min_tb);
                if(min_all > 1) {
                    tot++;
                }
            }            
        }
        cout << tot << endl;
    }
    return 0;
}
