#include <stdio.h>
#define MAX 1000002

int arr[MAX];

int main()
{
  int nc, i = 0, j, t;
  scanf("%d", &nc);
  
  while(nc--)
  {
    scanf("%d", &t);
    arr[t+1]++;
  }  
  
  for(i=1; i<MAX; i++)
  {
    for(j=0; j<arr[i]; j++)
      printf("%d\n", i-1); 
  }
  
  return 0;
}
  