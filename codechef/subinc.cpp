#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int compute(int start, int end)
{
    //cout << "\trange start: " << start << "; range end: " << end << endl;
    long long int nelem = end - start + 1;
    return (nelem * (nelem + 1)) / 2;
}

long long int maxnd(vector<int>& arr) 
{
    int start = 0, end = 0;
    long long int ans = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) {
            ans += compute(start, end);
            start = i;
        }
        end = i;
    }
    ans += compute(start, end);
    return ans;
} 

int main()
{
    int nc, n;
    cin >> nc;
    while (nc--) {
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << maxnd(arr) << endl;
    }
    return 0;
}
