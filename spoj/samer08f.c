/*
 * SPOJ: Feynman
 * Category: Simple Coding
 */
#include <stdio.h>
int main() 
{
    int n, ns, i, tot;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        tot = 0;
        for (i = 1; i <= n; i++) {
            ns = n - (i - 1);
            tot += ns*ns;
        }
        printf("%d\n", tot);
    }
    return 0;
}
