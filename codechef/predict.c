#include <stdio.h>

int main()
{
    int nc;
    scanf("%d", &nc);
    while(nc--) {
        double px, mp = 0.0, tmp;
        int i, a, b;
        scanf("%lf", &px);
        a = 0, b = 10000;
        tmp = 2*(1-px)*a*px + 2*px*b*(1-px) - a*(1-px) - b*px;
        if(tmp > mp)
            mp = tmp;
        a = 10000, b = 0;
        tmp = 2*(1-px)*a*px + 2*px*b*(1-px) - a*(1-px) - b*px;
        if(tmp > mp)
            mp = tmp;
            
        printf("%.6f\n", 10000 + mp);
    }
    return 0;
}