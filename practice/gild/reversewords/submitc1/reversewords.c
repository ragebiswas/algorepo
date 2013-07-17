#include <stdio.h>
#include <string.h>

#define ia(x) ( (x>='A' && x<='Z') || (x>='a' && x<='z') || (x>='0' && x<='9') )
#define SZ 512

int main(int argc, char** argv)
{
    char line[SZ], word[SZ], rword[SZ], c;
    FILE* fin = fopen(argv[1], "rb");
        
    while(fgets(line, SZ, fin))
    {
        int len = 0, inword = 0;
        int i, j, k, sz = strlen(line);
        
        for(i=0; i<sz; ++i)
        {
            c = line[i];
            if(ia(c))
            {
                inword = 1;
                word[len++] = c;
            }
            else
            {
                if(inword)
                {
                    inword = 0; 
                    k = 0;
                    for(j = len-1; j >= 0; j--)
                        rword[k++] = word[j];
                    len = 0;
                    rword[k] = 0;
                    fputs(rword, stdout);
                }
                putchar(c);                
            }
        }        
        
        if(inword)
        {
            inword = 0;
            k = 0;
            for(j = len-1; j >= 0; j--)
                rword[k++] = word[j];
            rword[k] = 0;
            fputs(rword, stdout);
            len = 0;                    
        }
    }
    return 0;
}