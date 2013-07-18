#include <stdio.h>
#define ZERO "0.00"

int calc(double len) 
{
    double l, tl = 0.0;
    int nc = 0, dn = 1;
    while(tl < len) {
        l = 1.0/(++dn);
        tl += l;
        nc++;
    }
    return nc;
}


int main()
{
    char str[5];
    double l;

    while(1) {
        scanf("%s", str);
        if(!strcmp(str, ZERO))
            break;
        sscanf(str, "%lf", &l);
        printf("%d card(s)\n", calc(l));
    }
    return 0;
}
