#include <stdio.h>
int main()
{
    int i;
    double t = 0, m;
    for(i=0; i<12; i++)
    {
        scanf("%lf", &m);
        t += m;
    }
    printf("$%0.2f\n", t/12.0);
    return 0;
}
