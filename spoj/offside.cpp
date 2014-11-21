#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, d;
    while (1) {
        cin >> a >> d;
        if (a == 0 && d == 0) {
            break;
        }
        vector<int> A(a, 0), D(d, 0);
        for (int i = 0; i < a; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < d; i++) {
            cin >> D[i];
        }
        sort(A.begin(), A.end());
        sort(D.begin(), D.end());
        cout <<  ((A[0] < D[1]) ? 'Y' : 'N') << endl;
    }
    return 0;
}

