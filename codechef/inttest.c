// inttest
#include <stdio.h>

int main()
{
    int n, k, t, a = 0;
    scanf("%d%d", &n ,&k);
    while(n--)
    {
        scanf("%d", &t);
        if(t%k==0) a++;
    }
    printf("%d\n", a);
    return 0;
}