#include <iostream>
using namespace std;

int main()
{
    int nc;
    cin>>nc;
    int arr[20];
    
    while(nc--)
    {
        int n, m;
        cin>>n>>m;
        bool possible = false;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];            
            
        for(int i=0; i<(1<<n); i++)
        {
            int s = 0;
            for(int j=0; j<n; j++)
            {
                if(i & (1 << j))
                    s += arr[j];
            }
            
            if(s == m)
            {
                possible = true;
                break;
            }
        }
        
        cout<<( possible ? "Yes\n" : "No\n");
    }
    
    return 0;
}