#include <iostream>
#include <string>
#include <cmath>

using namespace std;



inline bool isprime(int n)
{
    if(n < 2) 
        return false;
        
    if(n == 2) 
        return true;
        
    for(int div = 3; div < sqrt(n * 1.0); div+=2)
    {
        if(n % div == 0)
            return false;
    } 
    return true;
}

int main()
{
    int ncases;
    cin>>ncases;
    int n1, n2;
    
    while(ncases--)
    {
        cin>>n1>>n2;
        //for(int j = n1; j <= n2; j++)
        for(int j = 1; j <= 1000000000; j++)
        {
            if((j > 3) && (j % 6 != 1) && (j % 6 != 5))
                continue;
            
            if(isprime(j))
                cout<<j<<endl;
        }
        return 0;
        cout<<endl;
    }
    return 0;
}