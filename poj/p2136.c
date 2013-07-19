#include <stdio.h>
#include <string.h>

char matrix[26][300];
int counts[26];
char line[80];

int main() 
{
    int i, j, f, m;

    while(fgets(line, sizeof(line), stdin) != 0) {
        for(i=0; i<strlen(line); i++) {
            if(isalpha(line[i])) {
                counts[line[i]-'A']++;
            }
        }
    }
    
    for(i=0; i<26; i++) {
        for(j=0; j<counts[i]; j++) {
            matrix[i][j] = '*';
        }
    }

    for(i=299; i>=0; i--) {
        f = -1;
        for(j=0; j<26; j++) {
            if(matrix[j][i] == '*') {
                m = i;
                f = j;
            }
        }
        if(f != -1) {
            for(j=0; j<f; j++) {
                if(matrix[j][m] == '*')
                    printf("* ");
                else 
                    printf("  ");
            }
            printf("*\n");
        }
    }
    for(i='A'; i<'Z'; i++)
        printf("%c ", i);
    printf("Z\n");
    return 0;
}
