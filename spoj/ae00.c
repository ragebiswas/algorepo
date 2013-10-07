/**
 * Problem: http://www.spoj.com/problems/AE00/
 * Category: Simple math
 */
#include <stdio.h>
int main() 
{
    int n, x, y, c = 0;
    scanf("%d", &n);
    for(x = 1; x <= n; x++) {
        for(y = x; y <= n; y++) {
            if(x * y <= n)
                c++;
        }
    }
    printf("%d\n", c);
    return 0;
}
    