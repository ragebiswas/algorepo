/**
 * Problem: http://www.spoj.com/problems/ARMY/
 * Category: Simple coding/math
 */
#include <stdio.h>
#define MAX(a, b) ((a >= b) ? a : b)

int main() {
    int nc, maxx = 0, maxy = 0, nx, ny, i, t;
    scanf("%d", &nc);
    while(nc--) {
        scanf("%d%d", &nx, &ny);
        for (i = 0; i < nx; i++) {
            scanf("%d", &t);
            maxx = MAX(maxx, t);
        }
        for (i = 0; i < ny; i++) {
            scanf("%d", &t);
            maxy = MAX(maxy, t);
        }
        if (maxx >= maxy)
            printf("Godzilla\n");
        else 
            printf("MechaGodzilla\n");
            
    }
    return 0;
}