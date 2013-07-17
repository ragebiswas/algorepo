#include <stdio.h>
#include <string.h>
#define MAX 512
int main(int argc, char** argv)
{
	FILE *fp = fopen(argv[1], "r");
	int idx, sum, c['z'+1], p[MAX], sz, i, j;
	char buf[MAX], bwt[MAX], in[MAX];
	while(fgets(buf, MAX, fp))
	{
        if(!sscanf(buf, "%d%s", &idx, bwt))
            break;
		sz = strlen(bwt);
        sum = 0;
		for(i=0; i<='z'; ++i) 
            c[i] = 0;
		for(i=0; i<sz; ++i)
		{
			p[i] = c[bwt[i]];
			c[bwt[i]]++;
		}
		for(i='A'; i<='z'; ++i)
		{
			sum += c[i];
			c[i] = sum-c[i];
		}
		j = idx;
		for(i=sz-1; i>=0; i--)
		{
			in[i] = bwt[j];
			j = p[j] + c[bwt[j]];
		}
		in[sz] = 0;
        printf("%s\n", in);
	}
    fclose(fp);
    return 0;
}
