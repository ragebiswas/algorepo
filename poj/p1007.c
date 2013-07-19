#include <stdio.h>
#include <string.h>

char str[100][51];
char tmp[51];

int getscore(char* s) 
{
    int i, j, t = 0, l = strlen(s);
    for(i=0; i<l-1; i++) {
        for(j=i+1; j<l; j++) {
            if(s[i] > s[j])
                t++;
        }
    }
    return t;
}

int main() 
{
    int n, m, i, j, d = 1;

    // input
    scanf("%d%d", &n, &m);
    for(i=0; i<m; i++) {
        scanf("%s", str[i]);
    }
    
    // bubble sort
    while(d) {
        d = 0;
        for(i=0; i<m-1; i++) {
            if(getscore(str[i]) > getscore(str[i+1])) {
                strcpy(tmp, str[i]);
                strcpy(str[i], str[i+1]);
                strcpy(str[i+1], tmp);
                d = 1;
            }
        }
    }

    // output
    for(i=0; i<m; i++) {
        printf("%s\n", str[i]);
    }
    return 0;
}
