#include <stdio.h>

int h = 2;
int v = 2;
long long cnt = 0;

void cr(register int x, register int y)
{
  if(x > h || y > v)
    return;

  if(x == h && y == v)
    cnt++;

  cr(x+1, y);
  cr(x, y+1);
}

int main()
{
  while(h <= 20)
  {
    cnt = 0;
    cr(0,0);
    printf("%d: %lld\n", h, cnt);
    h++;
    v++;
  }

  return 0;
}
