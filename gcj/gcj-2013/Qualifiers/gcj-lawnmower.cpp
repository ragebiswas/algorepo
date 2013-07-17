#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int n, m, t;
    int arr[100][100];
    
    cin >> t;
    for (int c = 1; c <= t; ++c) {
        vector<int> maxrow(100, 0), maxcol(100, 0);
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
                maxrow[i] = max(arr[i][j], maxrow[i]);
            }
        }
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                maxcol[j] = max(arr[i][j], maxcol[j]);
            }
        }
        
        bool valid = true;
        for (int i = 0; i < n && valid; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] != maxrow[i] && arr[i][j] != maxcol[j]) {
                    valid = false;
                    break;
                }
            }
        }
        
        if (valid) {
            cout << "Case #" << c << ": YES" << endl;
        } else {
            cout << "Case #" << c << ": NO" << endl;
        }
    }

    return 0;
 }