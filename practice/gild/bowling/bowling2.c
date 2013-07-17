#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SZ 100
int main(int argc, char **argv)
{
	enum { NORMAL, STRIKE, SPARE, EXTRA };
	char *line, *token, buf[SZ], dlm[] = " \n";
	FILE *fin = fopen(argv[1], "r");	

	while((line = fgets(buf, SZ-1, fin)) != NULL)
	{

		int total = 0, i = 0, j = 0, f = 0, frameover= 1;
		int scores[30] = { 0 }, info[30] = { NORMAL };
		

		token = strtok(line, dlm);
		while(token)
		{
			if(*token == 'X')
			{
				scores[i] = 10;
				total += 10;
				info[i] = STRIKE;
				f++;
				frameover = 1;
			}
			else if(*token == '/')
			{
				scores[i] = 10 - scores[i-1];
				total += scores[i];
				info[i] = SPARE;
				f++;
				frameover = 1;
			}
			else
			{
				scores[i] = atoi(token);
				total += scores[i];
				info[i] = NORMAL;
				if(frameover)
				{
					frameover = 0;
				}
				else
				{
					frameover = 1;
					f++;
				}
			}

			if(f > 10 || (f == 10 && !frameover))
			{
        info[i] = EXTRA;
				total -= scores[i];
			}


			if(i >= 1 && info[i-1] == SPARE)
			{
				scores[i-1] += scores[i];
				total += scores[i];
			}

			if(i >= 2 && info[i-2] == STRIKE)
			{
				scores[i-2] += (scores[i] + scores[i-1]);
				total += (scores[i] + scores[i-1]);
			}

			token = strtok(NULL, dlm);
			i++;
		}

		printf("%d\n", total);
	}
    
    return 0;
}