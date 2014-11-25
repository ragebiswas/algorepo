#include <iostream>
#include <vector>
using namespace std;

uint64_t merge(vector<uint64_t>& v, vector<uint64_t>& tmp, uint64_t p, uint64_t q, uint64_t r)
{
    uint64_t invcount = 0, i, j, k;
    i = p;
    j = q;
    k = p;
    while (i < q && j <= r) {
        if (v[i] <= v[j]) {
            tmp[k++] = v[i++];
        }
        else {
            tmp[k++] = v[j++];
            invcount += (q - i);
        }
    }

    while (i < q) {
        tmp[k++] = v[i++];
    }
    while (j <= r) {
        tmp[k++] = v[j++];
    }

    for(i = p; i <= r; i++) {
        v[i] = tmp[i];
    }
    return invcount;
}

uint64_t mergesort(vector<uint64_t>& v, vector<uint64_t>& tmp, uint64_t p, uint64_t r)
{
    uint64_t inversions = 0;
    if (p < r) {
        uint64_t q = (p + r)/2;
        inversions += mergesort(v, tmp, p, q); 
        inversions += mergesort(v, tmp, q + 1, r);
        inversions += merge(v, tmp, p, q + 1, r);
    }
    return inversions;
}

int main()
{
    int nc;
    cin >> nc;
    while (nc--) {
        int n;
        cin >> n;
        vector<uint64_t> arr(n, 0), tmp(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
        }
        cout <<  mergesort(arr, tmp, 0, n - 1) << endl;
    }
    return 0;
}
