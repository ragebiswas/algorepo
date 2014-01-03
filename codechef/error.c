/**
 * Problem: http://www.codechef.com/JAN14/problems/ERROR
 * Category: Simple coding
 */
#include <stdio.h>
#include <string.h>

char s[100001];

int main() 
{
    int i, nc;
    scanf("%d", &nc);
 
    for(i = 0; i < nc; i++) {
        scanf("%s", s);
        if(strstr(s, "010") || strstr(s, "101")) {
            printf("Good\n");
        }
        else {
            printf("Bad\n");
        }        
    }
    return 0;
}
    