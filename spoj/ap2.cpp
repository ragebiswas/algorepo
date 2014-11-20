#include <iostream>
using namespace std;

int main()
{
    int nc; 
    cin >> nc;
    while (nc--) {
        long long n1, n2, s, d, N, a;
        cin >> n1 >> n2 >> s;
        N = (s * 2) / (n1 + n2);
        cout << N << endl;
        d = (n2 - n1) / (N - 5);
        a = n1 - 2*d;
        for (int i = 1; i <= N; i++) {
            cout << a + (i - 1)*d << ' ';
        }
        cout << endl;
    }
    return 0;
}
