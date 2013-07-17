#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    int ncases;
    cin>>ncases;
    while(ncases--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr.begin(), arr.end());
        int tw = accumulate(arr.begin(), arr.end(), 0);
        int minw1 = accumulate(arr.begin(), arr.begin() + k, 0);
        int maxw1 = tw-minw1;
        int minw2 = accumulate(arr.begin(), arr.begin() + (n-k), 0);
        int maxw2 = tw-minw2;
        cout<<max(maxw2-minw2, maxw1-minw1)<<endl;
    }
    return 0;
}
        
