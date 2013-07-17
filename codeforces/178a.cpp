#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    int m;
    cin>>m;
    
    while(m--)
    {
        int w;
        cin>>w;
        w--;
        
        int b;
        cin>>b;
        
        int c = arr[w];
        int l = b-1;
        int r = c-b;
        
        arr[w] = 0;
        
        if(w != 0)
            arr[w-1] += l;
            
        if(w != n-1)
            arr[w+1] += r;
    }
    
    for(int i=0; i<n; i++)
        cout<<arr[i]<<endl;
    
    return 0;
}