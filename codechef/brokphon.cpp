#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nc, n;
    cin >> nc;
    while (nc--) 
    {
        int c = 0;
        cin >> n;
        vector<int> arr(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        arr[0] = arr[1];
        arr[n + 1] = arr[n];
        for (int i = 1; i <= n; i++) {
            if ((arr[i - 1] != arr[i]) || (arr[i + 1] != arr[i])) {
                c++;
            }
        }
        cout << c << endl;
    }

    return 0;
}
