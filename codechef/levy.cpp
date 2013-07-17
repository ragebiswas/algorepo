#include <iostream>
using namespace std;

int ans[10001];
int prime[10001];

bool isprime(int n)
{
	if(n==2)
		return true;
		
	if(n==1 || n%2==0)
		return false;		
		
	for(int k=3; k*k <= n; k+=2)
		if(n%k==0)
			return false;
	
	return true;
}

void init()
{
    for(int n=2; n<=10000; n++)
    {
        prime[n] = isprime(n);
    }
    
    for(int n=1; n<=10000; n++)
    {
        for(int p=1; p<=n; p++)
        {
            if(!prime[p])
                continue;
            
            if((n-p)%2 == 1)
                continue;

            int q = (n-p)/2;
            
            if(prime[q])
            {
                ans[n]++;
            }
        }
    }
}

int main()
{
    int nc, n;
    cin>>nc;
    init();
    while(nc--)
    {
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}