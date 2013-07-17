#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 3000

static const char *p1 = "1,1,1,1", *p2 = "2,2,2,2";
static char ringbuf[4][MAX], *ptr[4];

void onewins() { printf("%s", "1\n"); exit(0); }
void twowins() { printf("%s", "2\n"); exit(0); }

int main(int argc, char** argv)
{
	FILE* fp = fopen(argv[1], "r");	
	int i = 0, k = 0, l = 0, sz = 0, ended = 1;

	fgets(ringbuf[0], MAX, fp);
	sz = strlen(ringbuf[i++]) - 1;
	ptr[3] = ringbuf[0];

	while(fgets(ringbuf[i], MAX, fp))
	{
		ringbuf[i][strlen(ringbuf[i])-1] = 0;

		if(strstr(ringbuf[i], p1))
			onewins();

		if(strstr(ringbuf[i], p2))
			twowins();

		if(strstr(ringbuf[i], "0"))
			ended = 0;

		ptr[3] = ringbuf[i];
		ptr[0] = ringbuf[(i+1)%4];
		ptr[1] = ringbuf[(i+2)%4];
		ptr[2] = ringbuf[(i+3)%4];

		i = (i+1)%4;
		l++;

		if(l < 3)
			continue;

		for(k = 0; k<sz; ++k)
		{
			if(ptr[0][k] == '1' && ptr[1][k] == '1' && ptr[2][k] == '1' && ptr[3][k] == '1')
				onewins();

			if(ptr[0][k] == '2' && ptr[1][k] == '2' && ptr[2][k] == '2' && ptr[3][k] == '2')
				twowins();

			if(k + 6 < sz)
			{
				if(ptr[0][k] == '1' && ptr[1][k+2] == '1' && ptr[2][k+4] == '1' && ptr[3][k+6] == '1')
					onewins();

				if(ptr[0][k] == '2' && ptr[1][k+2] == '2' && ptr[2][k+4] == '2' && ptr[3][k+6] == '2')
					twowins();	
			}

			if(k >= 6)
			{
				if(ptr[0][k] == '1' && ptr[1][k-2] == '1' && ptr[2][k-4] == '1' && ptr[3][k-6] == '1')
					onewins();

				if(ptr[0][k] == '2' && ptr[1][k-2] == '2' && ptr[2][k-4] == '2' && ptr[3][k-6] == '2')
					twowins();	
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