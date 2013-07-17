#include <stdio.h>
#include <string.h>
#define MAX 3000

const char *p1 = "1,1,1,1", *p2 = "2,2,2,2";
char ringbuf[4][MAX];

int main(int argc, char** argv)
{
	FILE* fp = fopen(argv[1], "r");	
	int i = 0, k = 0, sz = 0, ended = 1;

	fgets(ringbuf[0], MAX, fp);
	sz = strlen(ringbuf[i++]) - 1;

	while(fgets(ringbuf[i], MAX, fp))
	{
		if(strstr(ringbuf[i], p1))
		{
			printf("1\n");
			return 0;
		}
		if(strstr(ringbuf[i], p2))
		{
			printf("2\n");
			return 0;
		}

		if(!strchr(ringbuf[i], '0'))
			ended = 0;

		i = (i+1)%4;

		for(k = 0; k<sz; ++k)
		{
			if(ringbuf[0][k] == '1' && ringbuf[1][k] == '1' && ringbuf[2][k] == '1' && ringbuf[3][k] == '1')
			{
				printf("1\n");
				return 0;
			}
			else if(ringbuf[0][k] == '2' && ringbuf[1][k] == '2' && ringbuf[2][k] == '2' && ringbuf[3][k] == '2')
			{
				printf("2\n");
				return 0;
			}
		}
	}

	if(ended)
		printf("draw\n");
	else 
		printf("play\n");

	fclose(fp);
	return 0;
}