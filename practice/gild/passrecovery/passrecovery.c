/*
 *
 * Solution for 'passrecovery'
 * Author: <rajorshi.biswas@gmail.com>
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int fnv_hash(void *key, int len)
{
    unsigned char *p = key;
    unsigned int h = 2166136261;
    int i;

    for ( i = 0; i < len; i++ )
        h = ( h * 16777619 ) ^ p[i];

    return h;
}

int main(int argc, char** argv)
{
    FILE *fin = fopen(argv[1], "r");
    char *crypted, word[100], pw[100], salt[3];
    char *words[8][1000];
    size_t index[8] = { 0 };
    size_t i, j, k, sz, idx;
    size_t len, left, right;
    const char* digits = "0248";
    char htab[1 << 16] = { 0 };
    unsigned int hash;

    if(argc != 2)
    {
        fprintf(stderr, "usage: %s <input file>\n", argv[0]);
        return 1;
    }

    /* read pwhash */
    fscanf(fin, "%s", pw);

    salt[0] = pw[0];
    salt[1] = pw[1];

    /* read words and populate map */
    while( !feof(fin) )
    {
        fscanf(fin, "%s", word);

        char* w = malloc(strlen(word) + 1);

        for(i = 0, j = 0; i < strlen(word); i++)
        {
            if(isalpha(word[i]))
                w[j++] = tolower(word[i]);
        }
        w[j] = 0;

        idx = strlen(w);

        if(idx > 7 || idx < 1)
            continue;

        hash = fnv_hash(w, idx) & 0xFFFF;

        if(htab[hash])
            continue;

        htab[hash] = 1;

        words[idx][index[idx]++] = w;
    }


    /* build all possible 5-8 char passwords and match crypts */
    for(len = 4; len <= 7; len++)
    {
        char* match = malloc(len * sizeof(char) + 2);

        for(left = 1; left < len; left++)
        {
            right = len - left;

            if(index[left] == 0 || index[right] == 0)
                continue;

            for(i = 0; i < index[left]; i++)
            {
                for(j = 0; j < index[right]; j++)
                {
                    for(k = 0; k < 4; k++)
                    {
                        match[0] = 0;

                        strcat(match, words[left][i]);
                        sz = strlen(match);
                        match[sz++] = digits[k];
                        match[sz] = 0;
                        strcat(match, words[right][j]);

                        crypted = (char*)crypt(match, salt); 

                        if(!strcmp(crypted, pw))
                        {
                            // found result
                            printf("%s\n", match);
                            return 0;
                        }
                    }
                }
            }
        }
        free(match);
    }

    return 0;
}
